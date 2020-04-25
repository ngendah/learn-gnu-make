.PHONY: all

all:
	tar -zcvf SOURCES/hello_app-1.0.tar.gz ../hello_app-1.0
	rpmbuild --define "_topdir `pwd`" -ba SPECS/hello_app.spec
	