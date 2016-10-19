from django.shortcuts import get_object_or_404, render, redirect
from django.http import HttpResponse, HttpResponseRedirect
from .models import Queue, Message, Color
from django.urls import reverse
from django.contrib.messages import error, success
from django.template import loader


def index(request):
    current_message_queue = Queue.objects.order_by('id')

    template = loader.get_template('messagereceiver/index.html')
    context = {
        'current_message_queue': current_message_queue,
    }

    # question = get_object_or_404(Question, pk=question_id)
    return HttpResponse(template.render(context, request))


def queue(request):
    # TODO: add check for POST to handle new message
    if request.method == 'POST':
        message = request.POST['message']
        added_by = request.POST['author']
        try:
            msg_obj = Message(message_text=message, added_by=added_by)
            # place holder for now. Colors of message will be randomized for cooler effect
            color_obj = Color.objects.get(id=5)
            msg_obj.save()
            new_item = Queue(message=msg_obj, color=color_obj)
            new_item.save()
        except Exception as e:
            error(request, e)
            return redirect(reverse('messagereceiver:index'))

        success(request, 'Your message has been added!')
        return redirect(reverse('messagereceiver:index'))

    else:
        return HttpResponse("you're getting the whole queue")


def q_next(request):
    return HttpResponse("You're getting the next on the queue which is id")


def queue_message(request, message_id):
    return HttpResponse("You've queued {}".format(message_id))


def message_details(request, message_id):
    return HttpResponse("You're checking out the details for message {}".format(message_id))


def remove(request, queue_pos):
    return HttpResponse("Removed #{} from queue".format(queue_pos))