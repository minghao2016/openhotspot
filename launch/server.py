# BSD 3-Clause License
# OpenHotspot Framework 0.1.4
# Copyright (c) 2017, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.
from __future__ import print_function

import os
import csv
import json
import collections
import numpy as np
from flask import Flask, render_template

app = Flask(__name__)

def _parse_csvfile(self):
    column = collections.defaultdict(list)
    with open(self.csvfile, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            for info, value in row.iteritems():
                column[info].append(value)
    return {
        "n_clusters": column["n_clusters"],
        "cluster_lat": column["cluster_lat"],
        "cluster_long": column["cluster_long"],
        "cluster_types": column["cluster_types"]
    }

@app.route('/')
def _plot_clusters():
    csvfile = "../data/prediction.csv"
    return render_template("base.html")

if __name__ == '__main__':
    app.run()
