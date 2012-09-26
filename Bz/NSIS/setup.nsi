; Script generated by the HM NIS Edit Script Wizard.

!include Library.nsh
!include x64.nsh

RequestExecutionLevel admin

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "BzEditor"
!define PRODUCT_VERSION "1.7.2"
!define PRODUCT_PUBLISHER "c.mos"
!define PRODUCT_WEB_SITE "http://www.vcraft.jp/"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\BzEditor"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\classic-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\classic-uninstall.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
;!insertmacro MUI_PAGE_LICENSE "${NSISDIR}\License.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Japanese"

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "${PRODUCT_NAME}-${PRODUCT_VERSION}.exe"
!ifdef DngrDir
 InstallDir ${DngrDir}
!else ifdef DngrUnDir
 InstallDir ${DngrUnDir}
!else
 InstallDir "$PROGRAMFILES\BzEditor"
!endif
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite on
  CreateDirectory "$SMPROGRAMS\BzEditor"
  File "..\Release\Bz.exe"
  File "data\Bz.GID"
  File "data\Bz.HLP"
  File "data\Bz.txt"
  File "..\Release\Bzres_us.dll"
  File "data\EBCDIC.def"
  SetOutPath "$APPDATA\BzEditor"
  SetOverwrite off
  File "data\Bz.def"
  SetOverwrite on
  SetOutPath "$INSTDIR"

SectionEnd

Section -AdditionalIcons
  CreateDirectory "$SMPROGRAMS\BzEditor"
  CreateShortCut "$SMPROGRAMS\BzEditor\Bz.lnk" "$INSTDIR\Bz.exe"
  CreateShortCut "$SENDTO\Bz.lnk" "$INSTDIR\Bz.exe"
  CreateShortCut "$SMPROGRAMS\BzEditor\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\Bz.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\Bz.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(MUI_UNTEXT_FINISH_SUBTITLE)"
FunctionEnd


Function .onInit
  SetRegView 32
  StrCpy $INSTDIR "$PROGRAMFILES\BzEditor"

  ReadRegStr $R0 HKLM \
  "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
  "UninstallString"
  StrCmp $R0 "" done
 
  MessageBox MB_OKCANCEL|MB_ICONEXCLAMATION \
  "${PRODUCT_NAME}は既にインストールされています。$\n$\nOKボタンをクリックすると前のバージョンを先に削除します。Cancelボタンをクリックするとそのまま上書きします。" \
  IDOK uninst
  Abort
  
;Run the uninstaller
uninst:
  ClearErrors
  ExecWait '$R0 _?=$INSTDIR' ;Do not copy the uninstaller to a temp file
;  Exec $INSTDIR\uninst.exe ; instead of the ExecWait line
 
  IfErrors no_remove_uninstaller
    ;You can either use Delete /REBOOTOK in the uninstaller or add some code
    ;here to remove the uninstaller. Use a registry key to check
    ;whether the user has chosen to uninstall. If you are using an uninstaller
    ;components page, make sure all sections are uninstalled.
  no_remove_uninstaller:
  
done:
FunctionEnd

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "$(^Name)を完全に削除しますがよろしいですか？" IDYES +2
  Abort

  SetRegView 32
  StrCpy $INSTDIR "$PROGRAMFILES\BzEditor"
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\Bz.exe"
;  Delete "$APPDATA\BzEditor\Bz.def"
  Delete "$INSTDIR\Bz.GID"
  Delete "$INSTDIR\Bz.HLP"
  Delete "$INSTDIR\Bz.txt"
  Delete "$INSTDIR\Bzres_us.dll"
  Delete "$INSTDIR\EBCDUC.def"

  Delete "$SMPROGRAMS\BzEditor\Uninstall.lnk"
  Delete "$SENDTO\Bz.lnk"

  RMDir "$SMPROGRAMS\BzEditor"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd
