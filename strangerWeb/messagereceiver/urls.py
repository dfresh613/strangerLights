from django.conf.urls import url

from . import views
app_name = 'messagereceiver'
urlpatterns = [
    url(r'^$', views.index, name='index'),
    #url(r'^(queue/?P<message_id>[0-9]+)$', views.queue_message, name="queue_message"),
    url(r'^(?P<queue_pos>[0-9]+)/remove/$', views.remove, name="remove"),
    url(r'^(?P<queue_pos>[0-9]+)/$', views.message_details, name="message_details"),
    url(r'^queue/(?P<queue_pos>[0-9]+/remove)', views.remove, name="remove"),
    url(r'^queue/(?P<message_id>[0-9]+)', views.message_details, name="message_details"),
    url(r'^queue/next', views.q_next, name="q_next"),
    url(r'^queue/', views.queue, name="queue"),

]