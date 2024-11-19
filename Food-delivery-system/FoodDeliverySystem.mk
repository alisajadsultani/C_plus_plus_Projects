##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FoodDeliverySystem
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="/Users/sajad/Documents/Food Delivery System  "
ProjectPath            :="/Users/sajad/Documents/Food Delivery System  /FoodDeliverySystem"
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/FoodDeliverySystem
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
OutputDirectory        :=/Users/sajad/Documents/Food Delivery System  /build-$(WorkspaceConfiguration)/bin
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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/BikeDeliveryPerson.cpp$(ObjectSuffix) $(IntermediateDirectory)/CarDeliveryPerson.cpp$(ObjectSuffix) $(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix) $(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Food Delivery System  /FoodDeliverySystem/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/BikeDeliveryPerson.cpp$(ObjectSuffix): BikeDeliveryPerson.cpp $(IntermediateDirectory)/BikeDeliveryPerson.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Food Delivery System  /FoodDeliverySystem/BikeDeliveryPerson.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BikeDeliveryPerson.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BikeDeliveryPerson.cpp$(DependSuffix): BikeDeliveryPerson.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BikeDeliveryPerson.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BikeDeliveryPerson.cpp$(DependSuffix) -MM BikeDeliveryPerson.cpp

$(IntermediateDirectory)/BikeDeliveryPerson.cpp$(PreprocessSuffix): BikeDeliveryPerson.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BikeDeliveryPerson.cpp$(PreprocessSuffix) BikeDeliveryPerson.cpp

$(IntermediateDirectory)/CarDeliveryPerson.cpp$(ObjectSuffix): CarDeliveryPerson.cpp $(IntermediateDirectory)/CarDeliveryPerson.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Food Delivery System  /FoodDeliverySystem/CarDeliveryPerson.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CarDeliveryPerson.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CarDeliveryPerson.cpp$(DependSuffix): CarDeliveryPerson.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CarDeliveryPerson.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CarDeliveryPerson.cpp$(DependSuffix) -MM CarDeliveryPerson.cpp

$(IntermediateDirectory)/CarDeliveryPerson.cpp$(PreprocessSuffix): CarDeliveryPerson.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CarDeliveryPerson.cpp$(PreprocessSuffix) CarDeliveryPerson.cpp

$(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix): I_Printing.cpp $(IntermediateDirectory)/I_Printing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Food Delivery System  /FoodDeliverySystem/I_Printing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/I_Printing.cpp$(DependSuffix): I_Printing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/I_Printing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/I_Printing.cpp$(DependSuffix) -MM I_Printing.cpp

$(IntermediateDirectory)/I_Printing.cpp$(PreprocessSuffix): I_Printing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/I_Printing.cpp$(PreprocessSuffix) I_Printing.cpp

$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix): Menu.cpp $(IntermediateDirectory)/Menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/sajad/Documents/Food Delivery System  /FoodDeliverySystem/Menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Menu.cpp$(DependSuffix): Menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Menu.cpp$(DependSuffix) -MM Menu.cpp

$(IntermediateDirectory)/Menu.cpp$(PreprocessSuffix): Menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Menu.cpp$(PreprocessSuffix) Menu.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


