# BSD 3-Clause License
# Canalysis (Crime Analysis) 0.1.0
# Copyright (c) 2016, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.
from __future__ import print_function

import os
import csv
import flask
import numpy as np
import collections

app = flask.Flask(__name__)


class Server(object):
    def __init__(self, csvfile=None, port=None):
        self.csvfile = csvfile
        self.port = port
        # variance scale of 5 miles
        self.variance_scale = 5
        # variance crime rate of 10 crimes or more in a single variance
        self.variance_rate = 10

    def _parse_csvfile(self):
        column = collections.defaultdict(list)

        with open(self.csvfile, "r") as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                for info, value in row.iteritems():
                    column[info].append(value)

        return column["lat"], column["long"]

    @app.route("/")
    def _variance(self):
        """
        """
        lat_column, long_column = self._parse_csvfile()

if __name__ == '__main__':
    server = Server(csvfile="src/templates/data/prediction.csv",
                    port="0.0.0.0")
    server._variance()
