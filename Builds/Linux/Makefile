# Automatically generated makefile, created by the Introjucer
# Don't edit this file! Your changes will be overwritten when you re-save the Introjucer project!

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(TARGET_ARCH),)
  TARGET_ARCH := -march=native
endif

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build
  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "~/SDKs/vstsdk2.4" -I "../../JuceLibraryCode"
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0
  CXXFLAGS += $(CFLAGS) 
  LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -shared -L"/usr/X11R6/lib/" -L"../../../../Documents/Developement/juce_source/juce/modules/bin" -lfreetype -lpthread -lrt -lX11 -lGL -lGLU -lXinerama -lasound 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "~/SDKs/vstsdk2.4" -I "../../JuceLibraryCode"
  TARGET := Plugin\ Test.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build
  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "~/SDKs/vstsdk2.4" -I "../../JuceLibraryCode"
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -fPIC -Os
  CXXFLAGS += $(CFLAGS) 
  LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -shared -L"/usr/X11R6/lib/" -L"../../../../Documents/Developement/juce_source/juce/modules/bin" -lfreetype -lpthread -lrt -lX11 -lGL -lGLU -lXinerama -lasound 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "~/SDKs/vstsdk2.4" -I "../../JuceLibraryCode"
  TARGET := Plugin\ Test.so
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

OBJECTS := \
  $(OBJDIR)/PluginProcessor_a059e380.o \
  $(OBJDIR)/PluginEditor_94d4fb09.o \
  $(OBJDIR)/juce_AudioProcessorExt_d040a81c.o \
  $(OBJDIR)/juce_PluginParameter_49508aad.o \
  $(OBJDIR)/juce_audio_basics_2cb80bf0.o \
  $(OBJDIR)/juce_audio_devices_649024ae.o \
  $(OBJDIR)/juce_audio_formats_93116e4e.o \
  $(OBJDIR)/juce_audio_processors_ee99f5a8.o \
  $(OBJDIR)/juce_core_f4b674d2.o \
  $(OBJDIR)/juce_data_structures_2af81f0e.o \
  $(OBJDIR)/juce_events_357e2846.o \
  $(OBJDIR)/juce_graphics_4da974aa.o \
  $(OBJDIR)/juce_gui_basics_baae7726.o \
  $(OBJDIR)/juce_gui_extra_ac703a2e.o \
  $(OBJDIR)/juce_RTAS_DigiCode1_fd8f0f15.o \
  $(OBJDIR)/juce_RTAS_DigiCode2_fd9d2696.o \
  $(OBJDIR)/juce_RTAS_DigiCode3_fdab3e17.o \
  $(OBJDIR)/juce_RTAS_Wrapper_6747216b.o \
  $(OBJDIR)/juce_VST_Wrapper_bb62e93d.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking Plugin Test
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning Plugin Test
	-@rm -f $(OUTDIR)/$(TARGET)
	-@rm -rf $(OBJDIR)/*
	-@rm -rf $(OBJDIR)

$(OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_AudioProcessorExt_d040a81c.o: ../../Source/juce_AudioProcessorExt.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_AudioProcessorExt.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_PluginParameter_49508aad.o: ../../Source/juce_PluginParameter.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_PluginParameter.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_basics_2cb80bf0.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_audio_basics/juce_audio_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_devices_649024ae.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_audio_devices/juce_audio_devices.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_formats_93116e4e.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_audio_formats/juce_audio_formats.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_audio_processors_ee99f5a8.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_audio_processors/juce_audio_processors.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_core_f4b674d2.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_core/juce_core.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_data_structures_2af81f0e.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_data_structures/juce_data_structures.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_events_357e2846.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_events/juce_events.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_graphics_4da974aa.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_graphics/juce_graphics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_basics_baae7726.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_gui_basics/juce_gui_basics.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_gui_extra_ac703a2e.o: ../../../../Documents/Developement/juce_source/juce/modules/juce_gui_extra/juce_gui_extra.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_RTAS_DigiCode1_fd8f0f15.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode1.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_RTAS_DigiCode1.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_RTAS_DigiCode2_fd9d2696.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_RTAS_DigiCode2.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_RTAS_DigiCode3_fdab3e17.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/RTAS/juce_RTAS_DigiCode3.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_RTAS_DigiCode3.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_RTAS_Wrapper_6747216b.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/RTAS/juce_RTAS_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_RTAS_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/juce_VST_Wrapper_bb62e93d.o: ../../JuceLibraryCode/modules/juce_audio_plugin_client/VST/juce_VST_Wrapper.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling juce_VST_Wrapper.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
