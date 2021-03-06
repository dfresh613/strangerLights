from __future__ import unicode_literals

from django.db import models


class Color(models.Model):
    color_name = models.CharField(max_length=20)
    r = models.IntegerField()
    g = models.IntegerField()
    b = models.IntegerField()

    def __str__(self):
        return self.color_name


class Message(models.Model):
    message_text = models.CharField(max_length=140)
    added_by = models.CharField(max_length=20, default="The Demogorgon")

    def __str__(self):
        return self.message_text


class Queue(models.Model):
    message = models.ForeignKey(Message)
    color = models.ForeignKey(Color, null=True)

    def __str__(self):
        return 'Message: '+self.message.__str__()+'\n Color: '+self.color.__str__()
    # TODO: Add another method for pushing the message here?
