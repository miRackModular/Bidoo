RACK_DIR ?= ../..

DISTRIBUTABLES += $(wildcard LICENSE*) res

FLAGS += -Idep/include -I./src/dep/dr_wav -I./src/dep/filters -I./src/dep/freeverb -I./src/dep/gverb/include -I./src/dep/lodepng -I./src/dep/pffft -I./src/dep

SOURCES = $(wildcard src/dep/filters/*.cpp src/dep/freeverb/*.cpp src/dep/lodepng/*.cpp src/dep/pffft/*.c src/dep/*.cpp)

SOURCES += src/plugin.cpp src/ACNE.cpp src/BAR.cpp src/BISTROT.cpp src/BORDL.cpp src/CANARD.cpp src/CHUTE.cpp src/CLACOS.cpp src/CURT.cpp src/DFUZE.cpp src/DTROY.cpp src/DUKE.cpp src/EMILE.cpp src/FFILTR.cpp src/FORK.cpp src/GARCON.cpp src/HCTIP.cpp src/HUITRE.cpp src/LATE.cpp src/LIMBO.cpp src/LIMONADE.cpp src/LOURDE.cpp src/MINIBAR.cpp src/MOIRE.cpp src/MS.cpp src/MU.cpp src/OUAIVE.cpp src/PENEQUE.cpp src/PERCO.cpp src/RABBIT.cpp src/REI.cpp src/SIGMA.cpp src/TIARE.cpp src/TOCANTE.cpp src/VOID.cpp src/ZINC.cpp src/ZOUMAI.cpp src/FREIN.cpp

include $(RACK_DIR)/plugin.mk
