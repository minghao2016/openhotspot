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
    """
    Summary: Parses predicted CSV files created by the C++ framework. Then displays the predicted
    clusters on the UI.
    """
    def __init__(self, csvfile=None, port=None):
        self.csvfile = csvfile
        self.port = port
        # minimum amount of crimes in a single variance
        self.variance_rate = 25

    def _parse_csvfile(self):
        column = collections.defaultdict(list())

        with open(self.csvfile, "r") as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                for info, value in row.iteritems():
                    column[info].append(value)

        return column

    @app.route("/")
    def _plot_variances(self):
        """Examines how the predicted CSV file template looks and how function locations
        the varances.

        CSV File Format
        >>> cluster1,cluster2, ...
        >>> (lat, long),(lat, long), ...
        >>> (lat, long),(lat, long), ...
        >>> ...

        Essentially, each column represents the variances that are going to be plotted on the UI.
        Some columns may have more values than others in which those clusters are the variances
        were criminal activity is most likely to occur.
        """
        column = self._parse_csvfile()

if __name__ == '__main__':
    server = Server(csvfile="src/templates/data/prediction.csv",
                    port="0.0.0.0")
    server._plot_variances()
