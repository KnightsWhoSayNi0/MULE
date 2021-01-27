# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= MULE
ICON ?= icon.png
DESCRIPTION ?= "M.U.L.E. for the 84+CE"
COMPRESSED ?= NO
ARCHIVED ?= NO

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
