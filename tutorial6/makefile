SUBDIRS = lib app

.PHONY: subdirs $(SUBDIRS) clean

 subdirs: $(SUBDIRS)

 $(SUBDIRS):
	$(MAKE) -C $@

app: lib

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done
