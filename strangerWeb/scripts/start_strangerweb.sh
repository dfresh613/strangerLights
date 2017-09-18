#!/bin/bash

### Script installs database migrations, and then uses uswgi and ngninx to provide the service to django
python manage.py migrate
#uwsgi --socket strangerweb.sock --module wsgi --chmod-socket=666
service nginx start
pwd
uwsgi --socket :8001 --wsgi-file wsgi.py
