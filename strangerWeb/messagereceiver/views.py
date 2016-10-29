from django.shortcuts import get_object_or_404, render, redirect
from django.http import HttpResponse, HttpResponseRedirect, JsonResponse
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
    if request.method == 'POST':
        message = request.POST['message']
        added_by = request.POST['author']
        try:
            msg_obj = Message(message_text=message, added_by=added_by)
            # place holder for now. Colors of message will be randomized for cooler effect
            msg_obj.save()
            new_item = Queue(message=msg_obj, color=None)
            new_item.save()
        except Exception as e:
            error(request, e)
            return redirect(reverse('messagereceiver:index'))

        success(request, 'Your message has been added!')
        return redirect(reverse('messagereceiver:index'))

    else:
        return HttpResponse("you're getting the whole queue")


def q_next(request):
    try:
        req_sucess=True
        next=Queue.objects.order_by('id')[0]
    except:
        next=None
        req_sucess=False

    response_data = {
        'success': req_sucess,
    }

    if req_sucess:
        response_data.update({'message':  next.message.message_text})
        """disable until color is supported on front end

        response_data.update({'r': next.color.r})
        response_data.update({'g': next.color.g})
        response_data.update({'b': next.color.b})

        """
        response_data.update({'id': next.id})

    return JsonResponse(response_data)


def queue_message(request, message_id):
    return HttpResponse("You've queued {}".format(message_id))


def message_details(request, message_id):
    return HttpResponse("You're checking out the details for message {}".format(message_id))


def remove(request, queue_pos):
    response_data={}
    try:
        Queue.objects.filter(id=queue_pos).delete()
        response_data.update({'success': True})
    except:
        response_data.update({'success': True})
    return JsonResponse(response_data)
