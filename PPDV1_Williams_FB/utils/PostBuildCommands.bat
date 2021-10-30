set ProjectDir=%~1
set TargetDir=%~2

xcopy "%ProjectDir%assets\" "%TargetDir%assets\" /E /Y