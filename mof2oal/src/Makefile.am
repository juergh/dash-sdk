
#SUBDIRS = src


bin_PROGRAMS = mof2oal
mof2oal_SOURCES = 	cimclass.cpp		\
			cimmethod.cpp		\
			cimparameter.cpp	\
			cimproperty.cpp		\
			cimreference.cpp	\
			mof2oal.cpp		\
			cimmof_lex.cpp		\
			cimmof_tab.cpp

#cimmoflex.cpp : cimmof.l
#	flex cimmof.l && mv lex.yy.c cimmof_lex.cpp

#cimmoftab.cpp : cimmof.y
#	bison -y cimmof.y && mv y.tab.c cimmof_tab.cpp

EXTRA_DIST = cimmof.l cimmof.y Makefile.grammar *.h
