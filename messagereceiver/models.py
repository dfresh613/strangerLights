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
    message_color = models.ForeignKey(Color)

    def __str__(self):
        return self.message_text
    # TODO: Add another method for pushing the message here?
