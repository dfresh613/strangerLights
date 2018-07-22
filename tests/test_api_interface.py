from slightstalkie.api_interface import ApiInterface, extract_message_and_pos
import pytest, responses, json


@responses.activate
def test_get_json():
    responses.add(responses.GET, 'http://hostname/test/uri',
                  json={'test': 'message'}, status=200)
    i = ApiInterface("hostname")
    data = i.get_json("http://hostname/test/uri", 200)
    assert isinstance(data, dict)
    assert data == {'test': 'message'}
    assert i.get_json("http://hostname/test/uri", 500) is None

    assert i.get_json("http://unconnectableuri/", 400) is None


def test_init():
    i = ApiInterface("hostname")
    assert i.address == "http://hostname/messagereceiver"
    assert i.queue_uri == "http://hostname/messagereceiver/queue"
    assert i.next_message_uri == "http://hostname/messagereceiver/queue/next"


@responses.activate
def test_get_queue():
    i = ApiInterface("hostname")
    responses.add(responses.GET, 'http://hostname/messagereceiver/queue',
                  json={'test': 'message'}, status=200)
    data = i.get_queue()
    assert type(data) is dict


@responses.activate
def test_get_next_message():
    responses.add(responses.GET, 'http://hostname/messagereceiver/queue/next',
                  status=200, json={'success': True,
                                    'message': "test",
                                    'id': 5})
    i = ApiInterface("hostname")
    message, position = i.get_next_message()
    assert message == "test"
    assert position == 5


def test_extract_message_and_pos_defaults():
    random_fallback_response = "Random", -1

    data = None
    assert extract_message_and_pos(data) == random_fallback_response

    data == {}
    assert extract_message_and_pos(data) == random_fallback_response

    data = {'success': True}
    assert extract_message_and_pos(data) == ("Unknown", -1)


def test_post_message():
    i = ApiInterface("hostname")
    i.post_message("message", "author")
    assert True



