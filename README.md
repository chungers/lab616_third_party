# Third Party Libraries #

## Introduction ##

This repository contains commonly used third party C++ libraries including

* Boost
* Google logging (glog)
* Google flags (gflags)
* Google tests (gtests)
* SQLite3
* ZMQ

## Guideline ##

### Adding new libraries ###
In general, this directory is for libraries that are compile-time dependencies
and not command line tools.  Command line tools should be added to the tools
repository.
