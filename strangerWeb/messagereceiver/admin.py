from django.contrib import admin

# Register your models here.
from django.contrib import admin
from .models import Color, Message, Queue
admin.site.register([Color, Message, Queue])
