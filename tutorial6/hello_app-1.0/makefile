SUBDIRS = lib app

.PHONY: all install uninstall clean $(SUBDIRS)

 all: $(SUBDIRS)

 $(SUBDIRS):
	$(MAKE) -C $@

app: lib

install:
	for dir in $(SUBDIRS); do \
		$(MAKE) install -C $$dir; \
	done

uninstall:
	for dir in $(SUBDIRS); do \
		$(MAKE) uninstall -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done
	-rm -f dist/*.tar.gz
