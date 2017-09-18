#!/usr/bin/env python
from distutils.core import setup
import setuptools
setup(name='slightsTalkie',
      version='0.0.4',
      description="Contains libraries to communicate with both the web application api and the arduino serial listener. "
                  "This allows for sending and retrieving messages from both interfaces. Will.py uses these libraries to"
                  " inform the arduino serial interface what messages is next in the queue",
      author='Douglas Rohde',
      author_email='douglas.rohde2@gmail.com',
      packages=['slightsTalkie'],
      keywords='strangerlights',
      url='https://github.com/dfresh613/strangerLights',
      license="MIT",
      install_requires=[
          'requests',
          'pyserial'
      ],
      scripts=['bin/slightsTalkie', 'bin/strangerapi'],
      classifiers=[
          'Development Status :: 4 - Beta',
          'Topic :: Other/Nonlisted Topic',
          'License :: OSI Approved :: MIT License',
          'Programming Language :: Python :: 2.7',
      ]

      )