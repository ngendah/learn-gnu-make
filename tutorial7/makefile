SUBDIRS = lib app

.PHONY: all install uninstall dist clean $(SUBDIRS)

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
	
dist:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done
	-mkdir $@
	tar -zcvf $@/hello_app-1.0.tar.gz makefile app lib

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done
	-rm -f dist/hello_app-1.0.tar.gz
