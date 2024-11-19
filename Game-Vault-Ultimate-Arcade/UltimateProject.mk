##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UltimateProject
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="/Users/sajad/Documents/Ultimate Project"
ProjectPath            :="/Users/sajad/Documents/Ultimate Project/UltimateProject"
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/UltimateProject
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ali Sajjad Sultani
Date                   :=12/08/2024
CodeLitePath           :=/Users/sajad/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/Users/sajad/Documents/Ultimate Project/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O0 -gdwarf-2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/LoginAndRegister.cpp$(ObjectSuffix) $(IntermediateDirectory)/Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix) $(IntermediateDirectory)/TicTacTo.cpp$(ObjectSuffix) $(IntermediateDirectory)/HangManGame.cpp$(ObjectSuffix) $(IntermediateDirectory)/RockPaperScissors.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/LoginAndRegister.cpp$(ObjectSuffix): LoginAndRegister.cpp $(IntermediateDirectory)/LoginAndRegister.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/LoginAndRegister.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LoginAndRegister.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LoginAndRegister.cpp$(DependSuffix): LoginAndRegister.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LoginAndRegister.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LoginAndRegister.cpp$(DependSuffix) -MM LoginAndRegister.cpp

$(IntermediateDirectory)/LoginAndRegister.cpp$(PreprocessSuffix): LoginAndRegister.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LoginAndRegister.cpp$(PreprocessSuffix) LoginAndRegister.cpp

$(IntermediateDirectory)/Account.cpp$(ObjectSuffix): Account.cpp $(IntermediateDirectory)/Account.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Account.cpp$(DependSuffix): Account.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Account.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Account.cpp$(DependSuffix) -MM Account.cpp

$(IntermediateDirectory)/Account.cpp$(PreprocessSuffix): Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Account.cpp$(PreprocessSuffix) Account.cpp

$(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix): I_Printing.cpp $(IntermediateDirectory)/I_Printing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/I_Printing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/I_Printing.cpp$(DependSuffix): I_Printing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/I_Printing.cpp$(DependSuffix) -MM I_Printing.cpp

$(IntermediateDirectory)/I_Printing.cpp$(PreprocessSuffix): I_Printing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/I_Printing.cpp$(PreprocessSuffix) I_Printing.cpp

$(IntermediateDirectory)/TicTacTo.cpp$(ObjectSuffix): TicTacTo.cpp $(IntermediateDirectory)/TicTacTo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/TicTacTo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TicTacTo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TicTacTo.cpp$(DependSuffix): TicTacTo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TicTacTo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TicTacTo.cpp$(DependSuffix) -MM TicTacTo.cpp

$(IntermediateDirectory)/TicTacTo.cpp$(PreprocessSuffix): TicTacTo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TicTacTo.cpp$(PreprocessSuffix) TicTacTo.cpp

$(IntermediateDirectory)/HangManGame.cpp$(ObjectSuffix): HangManGame.cpp $(IntermediateDirectory)/HangManGame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/HangManGame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HangManGame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HangManGame.cpp$(DependSuffix): HangManGame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HangManGame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/HangManGame.cpp$(DependSuffix) -MM HangManGame.cpp

$(IntermediateDirectory)/HangManGame.cpp$(PreprocessSuffix): HangManGame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HangManGame.cpp$(PreprocessSuffix) HangManGame.cpp

$(IntermediateDirectory)/RockPaperScissors.cpp$(ObjectSuffix): RockPaperScissors.cpp $(IntermediateDirectory)/RockPaperScissors.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Ultimate Project/UltimateProject/RockPaperScissors.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RockPaperScissors.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RockPaperScissors.cpp$(DependSuffix): RockPaperScissors.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RockPaperScissors.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RockPaperScissors.cpp$(DependSuffix) -MM RockPaperScissors.cpp

$(IntermediateDirectory)/RockPaperScissors.cpp$(PreprocessSuffix): RockPaperScissors.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RockPaperScissors.cpp$(PreprocessSuffix) RockPaperScissors.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


