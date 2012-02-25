#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
# Adding MPLAB X bin directory to path
PATH:=/Applications/microchip/mplabx/mplab_ide.app/Contents/Resources/mplab_ide/mplab_ide/modules/../../bin/:$(PATH)
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/delayNOP.o ${OBJECTDIR}/gameSM.o ${OBJECTDIR}/hamming.o ${OBJECTDIR}/io.o ${OBJECTDIR}/irSerial.o ${OBJECTDIR}/main.o ${OBJECTDIR}/parserSM.o ${OBJECTDIR}/playerInfo.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/utility.o
POSSIBLE_DEPFILES=${OBJECTDIR}/delayNOP.o.d ${OBJECTDIR}/gameSM.o.d ${OBJECTDIR}/hamming.o.d ${OBJECTDIR}/io.o.d ${OBJECTDIR}/irSerial.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/parserSM.o.d ${OBJECTDIR}/playerInfo.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/utility.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/delayNOP.o ${OBJECTDIR}/gameSM.o ${OBJECTDIR}/hamming.o ${OBJECTDIR}/io.o ${OBJECTDIR}/irSerial.o ${OBJECTDIR}/main.o ${OBJECTDIR}/parserSM.o ${OBJECTDIR}/playerInfo.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/utility.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH="/System/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Home/bin/"
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC="/Applications/microchip/mplabc30/v3.30c/bin/pic30-gcc"
# MP_BC is not defined
MP_AS="/Applications/microchip/mplabc30/v3.30c/bin/pic30-as"
MP_LD="/Applications/microchip/mplabc30/v3.30c/bin/pic30-ld"
MP_AR="/Applications/microchip/mplabc30/v3.30c/bin/pic30-ar"
DEP_GEN=${MP_JAVA_PATH}java -jar "/Applications/microchip/mplabx/mplab_ide.app/Contents/Resources/mplab_ide/mplab_ide/modules/../../bin/extractobjectdependencies.jar" 
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps
MP_CC_DIR="/Applications/microchip/mplabc30/v3.30c/bin"
# MP_BC_DIR is not defined
MP_AS_DIR="/Applications/microchip/mplabc30/v3.30c/bin"
MP_LD_DIR="/Applications/microchip/mplabc30/v3.30c/bin"
MP_AR_DIR="/Applications/microchip/mplabc30/v3.30c/bin"
# MP_BC_DIR is not defined

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24F16KA102
MP_LINKER_FILE_OPTION=,-Tp24F16KA102.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/delayNOP.o: delayNOP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/delayNOP.o.d 
	@${RM} ${OBJECTDIR}/delayNOP.o.ok ${OBJECTDIR}/delayNOP.o.err 
	@${FIXDEPS} "${OBJECTDIR}/delayNOP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delayNOP.o.d" -o ${OBJECTDIR}/delayNOP.o delayNOP.c  
	
${OBJECTDIR}/gameSM.o: gameSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/gameSM.o.d 
	@${RM} ${OBJECTDIR}/gameSM.o.ok ${OBJECTDIR}/gameSM.o.err 
	@${FIXDEPS} "${OBJECTDIR}/gameSM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/gameSM.o.d" -o ${OBJECTDIR}/gameSM.o gameSM.c  
	
${OBJECTDIR}/hamming.o: hamming.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/hamming.o.d 
	@${RM} ${OBJECTDIR}/hamming.o.ok ${OBJECTDIR}/hamming.o.err 
	@${FIXDEPS} "${OBJECTDIR}/hamming.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/hamming.o.d" -o ${OBJECTDIR}/hamming.o hamming.c  
	
${OBJECTDIR}/io.o: io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/io.o.d 
	@${RM} ${OBJECTDIR}/io.o.ok ${OBJECTDIR}/io.o.err 
	@${FIXDEPS} "${OBJECTDIR}/io.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/io.o.d" -o ${OBJECTDIR}/io.o io.c  
	
${OBJECTDIR}/irSerial.o: irSerial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/irSerial.o.d 
	@${RM} ${OBJECTDIR}/irSerial.o.ok ${OBJECTDIR}/irSerial.o.err 
	@${FIXDEPS} "${OBJECTDIR}/irSerial.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/irSerial.o.d" -o ${OBJECTDIR}/irSerial.o irSerial.c  
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  
	
${OBJECTDIR}/parserSM.o: parserSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/parserSM.o.d 
	@${RM} ${OBJECTDIR}/parserSM.o.ok ${OBJECTDIR}/parserSM.o.err 
	@${FIXDEPS} "${OBJECTDIR}/parserSM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/parserSM.o.d" -o ${OBJECTDIR}/parserSM.o parserSM.c  
	
${OBJECTDIR}/playerInfo.o: playerInfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/playerInfo.o.d 
	@${RM} ${OBJECTDIR}/playerInfo.o.ok ${OBJECTDIR}/playerInfo.o.err 
	@${FIXDEPS} "${OBJECTDIR}/playerInfo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/playerInfo.o.d" -o ${OBJECTDIR}/playerInfo.o playerInfo.c  
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o.ok ${OBJECTDIR}/uart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c  
	
${OBJECTDIR}/utility.o: utility.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/utility.o.d 
	@${RM} ${OBJECTDIR}/utility.o.ok ${OBJECTDIR}/utility.o.err 
	@${FIXDEPS} "${OBJECTDIR}/utility.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/utility.o.d" -o ${OBJECTDIR}/utility.o utility.c  
	
else
${OBJECTDIR}/delayNOP.o: delayNOP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/delayNOP.o.d 
	@${RM} ${OBJECTDIR}/delayNOP.o.ok ${OBJECTDIR}/delayNOP.o.err 
	@${FIXDEPS} "${OBJECTDIR}/delayNOP.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delayNOP.o.d" -o ${OBJECTDIR}/delayNOP.o delayNOP.c  
	
${OBJECTDIR}/gameSM.o: gameSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/gameSM.o.d 
	@${RM} ${OBJECTDIR}/gameSM.o.ok ${OBJECTDIR}/gameSM.o.err 
	@${FIXDEPS} "${OBJECTDIR}/gameSM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/gameSM.o.d" -o ${OBJECTDIR}/gameSM.o gameSM.c  
	
${OBJECTDIR}/hamming.o: hamming.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/hamming.o.d 
	@${RM} ${OBJECTDIR}/hamming.o.ok ${OBJECTDIR}/hamming.o.err 
	@${FIXDEPS} "${OBJECTDIR}/hamming.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/hamming.o.d" -o ${OBJECTDIR}/hamming.o hamming.c  
	
${OBJECTDIR}/io.o: io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/io.o.d 
	@${RM} ${OBJECTDIR}/io.o.ok ${OBJECTDIR}/io.o.err 
	@${FIXDEPS} "${OBJECTDIR}/io.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/io.o.d" -o ${OBJECTDIR}/io.o io.c  
	
${OBJECTDIR}/irSerial.o: irSerial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/irSerial.o.d 
	@${RM} ${OBJECTDIR}/irSerial.o.ok ${OBJECTDIR}/irSerial.o.err 
	@${FIXDEPS} "${OBJECTDIR}/irSerial.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/irSerial.o.d" -o ${OBJECTDIR}/irSerial.o irSerial.c  
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o.ok ${OBJECTDIR}/main.o.err 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c  
	
${OBJECTDIR}/parserSM.o: parserSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/parserSM.o.d 
	@${RM} ${OBJECTDIR}/parserSM.o.ok ${OBJECTDIR}/parserSM.o.err 
	@${FIXDEPS} "${OBJECTDIR}/parserSM.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/parserSM.o.d" -o ${OBJECTDIR}/parserSM.o parserSM.c  
	
${OBJECTDIR}/playerInfo.o: playerInfo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/playerInfo.o.d 
	@${RM} ${OBJECTDIR}/playerInfo.o.ok ${OBJECTDIR}/playerInfo.o.err 
	@${FIXDEPS} "${OBJECTDIR}/playerInfo.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/playerInfo.o.d" -o ${OBJECTDIR}/playerInfo.o playerInfo.c  
	
${OBJECTDIR}/uart.o: uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o.ok ${OBJECTDIR}/uart.o.err 
	@${FIXDEPS} "${OBJECTDIR}/uart.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c  
	
${OBJECTDIR}/utility.o: utility.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/utility.o.d 
	@${RM} ${OBJECTDIR}/utility.o.ok ${OBJECTDIR}/utility.o.err 
	@${FIXDEPS} "${OBJECTDIR}/utility.o.d" $(SILENT) -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/utility.o.d" -o ${OBJECTDIR}/utility.o utility.c  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}        -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}/pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/lasertag.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "/Applications/microchip/mplabx/mplab_ide.app/Contents/Resources/mplab_ide/mplab_ide/modules/../../bin/"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
