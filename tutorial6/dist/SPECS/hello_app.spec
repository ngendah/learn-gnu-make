

Name:           hello_app
Version:        1.0
Release:        1%{?dist}
Summary:        Hello world app


License:        Apache2
URL:			https://github.com/ngendah/learn_gnu_make
Source0:		hello_app-1.0.tar.gz
BuildRequires:  gcc
BuildRequires: 	make

%global debug_package %{nil}

%description
A hello app rpm build

%prep

%setup -n %{name}-%{version}

%build
make %{?_smp_mlags}

%install
make destdir=$RPM_BUILD_ROOT install

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root)
%{_bindir}/hello_app
%{_libdir}/libapp.so*


%changelog

