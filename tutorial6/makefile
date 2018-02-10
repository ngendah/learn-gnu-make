SUBDIRS = lib app

.PHONY: subdirs $(SUBDIRS)

 subdirs: $(SUBDIRS)

 $(SUBDIRS):
	$(MAKE) -C $@

app: lib

.CLEAN: clean

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done
