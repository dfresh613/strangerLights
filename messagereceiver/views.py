from django.http import HttpResponse
from .models import Queue, Message, Color
from django.template import loader


def index(request):
    current_message_queue = Queue.objects.order_by('id')

    template = loader.get_template('messagereceiver/index.html')
    context = {
        'current_message_queue': current_message_queue,
    }

    #question = get_object_or_404(Question, pk=question_id)
    return HttpResponse(template.render(context, request))


def queue(request):
    # TODO: add check for POST to handle new message
    return HttpResponse("you're getting the whole queue")


def q_next(request):
    return HttpResponse("You're getting the next on the queue which is id")


def queue_message(request, message_id):
    return HttpResponse("You've queued {}".format(message_id))


def message_details(request, message_id):
    return HttpResponse("You're checking out the details for message {}".format(message_id))


def remove(request, queue_pos):
    return HttpResponse("Removed #{} from queue".format(queue_pos))