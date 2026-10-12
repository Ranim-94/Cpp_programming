#!/bin/bash
# Generates Eclipse CDT .project and .cproject files for every subdirectory.
# Uses Eclipse Managed Build System (Linux GCC toolchain) — Debug + Release configs.

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$BASE_DIR"

for dir in */; do
    dir="${dir%/}"
    N="$dir"

    # ── .project ──────────────────────────────────────────────────────────────
    cat > "$dir/.project" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<projectDescription>
<name>${N}</name>
<comment></comment>
<projects>
</projects>
<buildSpec>
<buildCommand>
<name>org.eclipse.cdt.managedbuilder.core.genmakebuilder</name>
<triggers>clean,full,incremental,</triggers>
<arguments>
</arguments>
</buildCommand>
<buildCommand>
<name>org.eclipse.cdt.managedbuilder.core.ScannerConfigBuilder</name>
<triggers>full,incremental,</triggers>
<arguments>
</arguments>
</buildCommand>
</buildSpec>
<natures>
<nature>org.eclipse.cdt.core.cnature</nature>
<nature>org.eclipse.cdt.core.ccnature</nature>
<nature>org.eclipse.cdt.managedbuilder.core.managedBuildNature</nature>
<nature>org.eclipse.cdt.managedbuilder.core.ScannerConfigNature</nature>
</natures>
</projectDescription>
EOF

    # ── .cproject ─────────────────────────────────────────────────────────────
    cat > "$dir/.cproject" << EOF
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?fileVersion 4.0.0?><cproject storage_type_id="org.eclipse.cdt.core.XmlProjectDescriptionStorage">
<storageModule moduleId="org.eclipse.cdt.core.settings">
<cconfiguration id="cdt.managedbuild.config.gnu.exe.debug.${N}">
<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider"
               id="cdt.managedbuild.config.gnu.exe.debug.${N}"
               moduleId="org.eclipse.cdt.core.settings"
               name="Debug">
<externalSettings/>
<extensions>
<extension id="org.eclipse.cdt.core.ELF"             point="org.eclipse.cdt.core.BinaryParser"/>
<extension id="org.eclipse.cdt.core.GASErrorParser"  point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.GLDErrorParser"  point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.CWDLocator"      point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.GCCErrorParser"  point="org.eclipse.cdt.core.ErrorParser"/>
</extensions>
</storageModule>
<storageModule moduleId="cdtBuildSystem" version="4.0.0">
<configuration
artifactName="\${ProjName}"
buildArtefactType="org.eclipse.cdt.build.core.buildArtefactType.exe"
buildProperties="org.eclipse.cdt.build.core.buildType=org.eclipse.cdt.build.core.buildType.debug,org.eclipse.cdt.build.core.buildArtefactType=org.eclipse.cdt.build.core.buildArtefactType.exe"
cleanCommand="rm -rf"
description=""
errorParsers="org.eclipse.cdt.core.GASErrorParser;org.eclipse.cdt.core.GmakeErrorParser;org.eclipse.cdt.core.GLDErrorParser;org.eclipse.cdt.core.CWDLocator;org.eclipse.cdt.core.GCCErrorParser"
id="cdt.managedbuild.config.gnu.exe.debug.${N}"
name="Debug"
parent="cdt.managedbuild.config.gnu.exe.debug">
<folderInfo id="cdt.managedbuild.config.gnu.exe.debug.${N}./" name="/" resourcePath="">
<toolChain id="cdt.managedbuild.toolchain.gnu.exe.debug.${N}"
           name="Linux GCC"
           superClass="cdt.managedbuild.toolchain.gnu.exe.debug">
<targetPlatform
binaryParser="org.eclipse.cdt.core.ELF"
id="cdt.managedbuild.target.gnu.platform.exe.debug.${N}"
name="Debug Platform"
superClass="cdt.managedbuild.target.gnu.platform.exe.debug"/>
<builder
buildPath="\${workspace_loc:/${N}}/Debug"
id="cdt.managedbuild.target.gnu.builder.exe.debug.${N}"
keepEnvironmentInBuildfile="false"
managedBuildOn="true"
name="Gnu Make Builder"
superClass="cdt.managedbuild.target.gnu.builder.exe.debug"/>
<tool id="cdt.managedbuild.tool.gnu.archiver.base.dbg.${N}"
      name="GCC Archiver"
      superClass="cdt.managedbuild.tool.gnu.archiver.base"/>
<tool id="cdt.managedbuild.tool.gnu.cpp.compiler.exe.debug.${N}"
      name="GCC C++ Compiler"
      superClass="cdt.managedbuild.tool.gnu.cpp.compiler.exe.debug">
<option id="gnu.cpp.compiler.exe.debug.option.optimization.value.${N}"
        name="Optimization Level"
        superClass="gnu.cpp.compiler.exe.debug.option.optimization.value"
        value="gnu.cpp.compiler.optimization.value.none"
        valueType="enumerated"/>
<option id="gnu.cpp.compiler.exe.debug.option.debugging.value.${N}"
        name="Debug Level"
        superClass="gnu.cpp.compiler.exe.debug.option.debugging.value"
        value="gnu.cpp.compiler.debugging.level.max"
        valueType="enumerated"/>
<inputType id="cdt.managedbuild.tool.gnu.cpp.compiler.input.dbg.${N}"
           superClass="cdt.managedbuild.tool.gnu.cpp.compiler.input"/>
</tool>
<tool id="cdt.managedbuild.tool.gnu.c.compiler.exe.debug.${N}"
      name="GCC C Compiler"
      superClass="cdt.managedbuild.tool.gnu.c.compiler.exe.debug">
<option id="gnu.c.compiler.exe.debug.option.optimization.value.${N}"
        name="Optimization Level"
        superClass="gnu.c.compiler.exe.debug.option.optimization.value"
        value="gnu.c.compiler.optimization.value.none"
        valueType="enumerated"/>
<option id="gnu.c.compiler.exe.debug.option.debugging.value.${N}"
        name="Debug Level"
        superClass="gnu.c.compiler.exe.debug.option.debugging.value"
        value="gnu.c.compiler.debugging.level.max"
        valueType="enumerated"/>
<inputType id="cdt.managedbuild.tool.gnu.c.compiler.input.dbg.${N}"
           superClass="cdt.managedbuild.tool.gnu.c.compiler.input"/>
</tool>
<tool id="cdt.managedbuild.tool.gnu.c.linker.exe.debug.${N}"
      name="GCC C Linker"
      superClass="cdt.managedbuild.tool.gnu.c.linker.exe.debug"/>
<tool id="cdt.managedbuild.tool.gnu.cpp.linker.exe.debug.${N}"
      name="GCC C++ Linker"
      superClass="cdt.managedbuild.tool.gnu.cpp.linker.exe.debug">
<inputType id="cdt.managedbuild.tool.gnu.cpp.linker.input.dbg.${N}"
           superClass="cdt.managedbuild.tool.gnu.cpp.linker.input">
<additionalInput kind="additionalinputdependency" paths="\$(USER_OBJS)"/>
<additionalInput kind="additionalinput"           paths="\$(LIBS)"/>
</inputType>
</tool>
<tool id="cdt.managedbuild.tool.gnu.assembler.exe.debug.${N}"
      name="GCC Assembler"
      superClass="cdt.managedbuild.tool.gnu.assembler.exe.debug">
<inputType id="cdt.managedbuild.tool.gnu.assembler.input.dbg.${N}"
           superClass="cdt.managedbuild.tool.gnu.assembler.input"/>
</tool>
</toolChain>
</folderInfo>
</configuration>
</storageModule>
<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
</cconfiguration>
<cconfiguration id="cdt.managedbuild.config.gnu.exe.release.${N}">
<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider"
               id="cdt.managedbuild.config.gnu.exe.release.${N}"
               moduleId="org.eclipse.cdt.core.settings"
               name="Release">
<externalSettings/>
<extensions>
<extension id="org.eclipse.cdt.core.ELF"             point="org.eclipse.cdt.core.BinaryParser"/>
<extension id="org.eclipse.cdt.core.GASErrorParser"   point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.GmakeErrorParser" point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.GLDErrorParser"   point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.CWDLocator"       point="org.eclipse.cdt.core.ErrorParser"/>
<extension id="org.eclipse.cdt.core.GCCErrorParser"   point="org.eclipse.cdt.core.ErrorParser"/>
</extensions>
</storageModule>
<storageModule moduleId="cdtBuildSystem" version="4.0.0">
<configuration
artifactName="\${ProjName}"
buildArtefactType="org.eclipse.cdt.build.core.buildArtefactType.exe"
buildProperties="org.eclipse.cdt.build.core.buildType=org.eclipse.cdt.build.core.buildType.release,org.eclipse.cdt.build.core.buildArtefactType=org.eclipse.cdt.build.core.buildArtefactType.exe"
cleanCommand="rm -rf"
description=""
errorParsers="org.eclipse.cdt.core.GASErrorParser;org.eclipse.cdt.core.GmakeErrorParser;org.eclipse.cdt.core.GLDErrorParser;org.eclipse.cdt.core.CWDLocator;org.eclipse.cdt.core.GCCErrorParser"
id="cdt.managedbuild.config.gnu.exe.release.${N}"
name="Release"
parent="cdt.managedbuild.config.gnu.exe.release">
<folderInfo id="cdt.managedbuild.config.gnu.exe.release.${N}./" name="/" resourcePath="">
<toolChain id="cdt.managedbuild.toolchain.gnu.exe.release.${N}"
           name="Linux GCC"
           superClass="cdt.managedbuild.toolchain.gnu.exe.release">
<targetPlatform
binaryParser="org.eclipse.cdt.core.ELF"
id="cdt.managedbuild.target.gnu.platform.exe.release.${N}"
name="Release Platform"
superClass="cdt.managedbuild.target.gnu.platform.exe.release"/>
<builder
buildPath="\${workspace_loc:/${N}}/Release"
id="cdt.managedbuild.target.gnu.builder.exe.release.${N}"
keepEnvironmentInBuildfile="false"
managedBuildOn="true"
name="Gnu Make Builder"
superClass="cdt.managedbuild.target.gnu.builder.exe.release"/>
<tool id="cdt.managedbuild.tool.gnu.archiver.base.rel.${N}"
      name="GCC Archiver"
      superClass="cdt.managedbuild.tool.gnu.archiver.base"/>
<tool id="cdt.managedbuild.tool.gnu.cpp.compiler.exe.release.${N}"
      name="GCC C++ Compiler"
      superClass="cdt.managedbuild.tool.gnu.cpp.compiler.exe.release">
<option id="gnu.cpp.compiler.exe.release.option.optimization.value.${N}"
        name="Optimization Level"
        superClass="gnu.cpp.compiler.exe.release.option.optimization.value"
        value="gnu.cpp.compiler.optimization.value.optimize"
        valueType="enumerated"/>
<option id="gnu.cpp.compiler.exe.release.option.debugging.value.${N}"
        name="Debug Level"
        superClass="gnu.cpp.compiler.exe.release.option.debugging.value"
        value="gnu.cpp.compiler.debugging.level.none"
        valueType="enumerated"/>
<inputType id="cdt.managedbuild.tool.gnu.cpp.compiler.input.rel.${N}"
           superClass="cdt.managedbuild.tool.gnu.cpp.compiler.input"/>
</tool>
<tool id="cdt.managedbuild.tool.gnu.c.compiler.exe.release.${N}"
      name="GCC C Compiler"
      superClass="cdt.managedbuild.tool.gnu.c.compiler.exe.release">
<option id="gnu.c.compiler.exe.release.option.optimization.value.${N}"
        name="Optimization Level"
        superClass="gnu.c.compiler.exe.release.option.optimization.value"
        value="gnu.c.compiler.optimization.value.optimize"
        valueType="enumerated"/>
<option id="gnu.c.compiler.exe.release.option.debugging.value.${N}"
        name="Debug Level"
        superClass="gnu.c.compiler.exe.release.option.debugging.value"
        value="gnu.c.compiler.debugging.level.none"
        valueType="enumerated"/>
<inputType id="cdt.managedbuild.tool.gnu.c.compiler.input.rel.${N}"
           superClass="cdt.managedbuild.tool.gnu.c.compiler.input"/>
</tool>
<tool id="cdt.managedbuild.tool.gnu.c.linker.exe.release.${N}"
      name="GCC C Linker"
      superClass="cdt.managedbuild.tool.gnu.c.linker.exe.release"/>
<tool id="cdt.managedbuild.tool.gnu.cpp.linker.exe.release.${N}"
      name="GCC C++ Linker"
      superClass="cdt.managedbuild.tool.gnu.cpp.linker.exe.release">
<inputType id="cdt.managedbuild.tool.gnu.cpp.linker.input.rel.${N}"
           superClass="cdt.managedbuild.tool.gnu.cpp.linker.input">
<additionalInput kind="additionalinputdependency" paths="\$(USER_OBJS)"/>
<additionalInput kind="additionalinput"           paths="\$(LIBS)"/>
</inputType>
</tool>
<tool id="cdt.managedbuild.tool.gnu.assembler.exe.release.${N}"
      name="GCC Assembler"
      superClass="cdt.managedbuild.tool.gnu.assembler.exe.release">
<inputType id="cdt.managedbuild.tool.gnu.assembler.input.rel.${N}"
           superClass="cdt.managedbuild.tool.gnu.assembler.input"/>
</tool>
</toolChain>
</folderInfo>
</configuration>
</storageModule>
<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>
</cconfiguration>
</storageModule>
<storageModule moduleId="cdtBuildSystem" version="4.0.0">
<project id="${N}.cdt.managedbuild.target.gnu.exe" name="Executable" projectType="cdt.managedbuild.target.gnu.exe"/>
</storageModule>
<storageModule moduleId="org.eclipse.cdt.core.LanguageSettingsProviders"/>
<storageModule moduleId="refreshScope" versionNumber="2">
<configuration configurationName="Debug">
<resource resourceType="PROJECT" workspacePath="/${N}"/>
</configuration>
<configuration configurationName="Release">
<resource resourceType="PROJECT" workspacePath="/${N}"/>
</configuration>
</storageModule>
<storageModule moduleId="scannerConfiguration">
<autodiscovery enabled="true" problemReportingEnabled="true" selectedProfileId=""/>
</storageModule>
</cproject>
EOF

    echo "Created .project + .cproject for: $dir"
done

echo ""
echo "All done."
