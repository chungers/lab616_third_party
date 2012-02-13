#!/bin/bash

R CMD INSTALL Rcpp_0.9.9.tar.gz 
R CMD INSTALL iterators_1.0.5.tar.gz foreach_1.3.2.tar.gz 
R CMD INSTALL int64_1.1.2.tar.gz 
R CMD INSTALL bigmemory_4.2.11.tar.gz 
R CMD INSTALL zoo_1.7-6.tar.gz xts_0.8-2.tar.gz TTR_0.21-0.tar.gz Defaults_1.1-1.tar.gz quantmod_0.3-17.tar.gz 
R CMD INSTALL bit_1.1-7.tar.gz ff_2.2-3.tar.gz 
R CMD INSTALL lubridate_0.2.6.tar.gz 

