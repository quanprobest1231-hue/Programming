.PHONY: rule1 rule2 rule3

var := "var"
var3 := "var3"
include abcd.mk

var1 = ${var}
var2 := ${var}
var3 ?= ${var}

var := "changed_var"

rule3:
	@echo "${var1}"
	@echo "${var2}"
	@echo "${var3}"

rule1:
	echo "This is rule1"

rule2:
	@echo "This is rule2"