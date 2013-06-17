
OBJECTFILES = FrequencyExtractor.obj
DUMPFILE = datadump.txt


prog: $(OBJECTFILES)
	cl /EHsc /FeFE $(OBJECTFILES)
	
run:
	FE "$(DUMPFILE)"