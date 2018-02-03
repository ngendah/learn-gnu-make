SUBDIRS = app1 app2

.PHONY: subdirs $(SUBDIRS)

 subdirs: $(SUBDIRS)

 $(SUBDIRS):
	$(MAKE) -C $@

app2: app1

.CLEAN: clean
.CLEANALL: cleanall

clean:
	$(MAKE) clean -C app1
	$(MAKE) clean -C app2

cleanall:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done
