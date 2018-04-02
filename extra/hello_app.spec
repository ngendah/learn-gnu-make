Name:           hello_app
Version:        1.0
Release:        1%{?dist}
Summary:        Hello world app

License:        Apache2
URL:			https://github.com/ngendah/learn_gnu_make

BuildRequires:  gcc
BuildRequires: 	make

%description
A hello app rpm build


%prep
%autosetup


%build
%configure
make %{?_smp_mflags}


%install
%make_install


%files
%doc add-docs-here



%changelog
* Mon Apr  2 2018 ngenda <ngendahk@gmail.com>
- 
