#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the Common Development
# and Distribution License Version 1.0 (the "License").
#
# You can obtain a copy of the license at
# http://www.opensource.org/licenses/CDDL-1.0.  See the License for the
# specific language governing permissions and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each file and
# include the License file in a prominent location with the name LICENSE.CDDL.
# If applicable, add the following below this CDDL HEADER, with the fields
# enclosed by brackets "[]" replaced with your own identifying information:
#
# Portions Copyright (c) [yyyy] [name of copyright owner]. All rights reserved.
#
# CDDL HEADER END
#

#
# Copyright (c) 2013--2014, Regents of the University of Minnesota.
# All rights reserved.
#
# Contributors:
#    Ryan S. Elliott
#

#
# Release: This file is part of the kim-api.git repository.
#


#
# this make file builds/cleans the examples
#

.PHONY: all

KIM_DIR := ../..
KIM_EX_DIR := $(KIM_DIR)/examples

all:
	cp examples_Makefile $(KIM_EX_DIR)/Makefile
	$(MAKE) -C model_legos all
	@printf "\n"
	$(MAKE) -C simulator_legos all
	@printf "\n"
	$(MAKE) -C openkim_test_legos all