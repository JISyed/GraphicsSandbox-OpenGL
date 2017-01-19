echo "Copying DLLs into Debug build..."
IF exist Debug\ ( xcopy /R /Y .\..\..\thirdparty\freetype\freetype6.dll Debug\ )
IF exist Debug\ ( xcopy /R /Y .\..\..\thirdparty\irrklang\irrklang.dll Debug\ )
IF exist Debug\ ( xcopy /R /Y .\..\..\thirdparty\irrklang\ikpMP3.dll Debug\ )
IF exist Debug\ ( xcopy /R /Y .\..\..\thirdparty\oail\assimp-vc120-mt.dll Debug\ )
echo "Copying DLLS into Release build..."
IF exist Release\ ( xcopy /R /Y .\..\..\thirdparty\freetype\freetype6.dll Release\ )
IF exist Release\ ( xcopy /R /Y .\..\..\thirdparty\irrklang\irrklang.dll Release\ )
IF exist Release\ ( xcopy /R /Y .\..\..\thirdparty\irrklang\ikpMP3.dll Release\ )
IF exist Release\ ( xcopy /R /Y .\..\..\thirdparty\oail\assimp-vc120-mt.dll Release\ )