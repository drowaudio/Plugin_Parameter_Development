Steps to build in XCode:

- Open Introjucer project (N.B. juce_audio_plugin_client module has to be copied into the project folder)

- Update the following
  Modules -> Module source folder
  Xcode (MacOSX) -> Local JUCE folder, VST Folder

- Save and open in XCode

- Remove juce_AU_Wrapper.mm from JuceLibraryCode group (this is replaced by our juce_AU_WrapperExt.mm file)

- Add AU Lab as a custom executable and set the "Plugin Test AU Lab Settings" file as the argument if desired
