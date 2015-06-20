#Welcome to Lucarne

Lucarne is a plateform game, developed by twelve students from an engineering school (Mines Nancy) and an art school (ENSA Nancy).


##Getting Started
 
To work on the project, you need:
 - CMake
 - Python 3 or above
 - Visual Studio 2013 or above
 
 Then, launch CMake and configure :
 - The sources to src-2015 folder
 - The build path to the BUILD folder (if it doesn't exist, create it)
 
 You should now have a fully functional version of Lucarne
 
 
##Testing sprites with this project
 
 - All content should be added to src-2015\data
 - Scripts should be placed in src-2015\data\scripts
 - To launch the game, go to BUILD\src-2015

## Générer l'installeur vous même 
D'abord le code ne doit pas contenir sourcepath() il faut tous les remplacer par executablepath(), et aussi si vous avez ajouter un fichier Data au projet il faut l'ajouter aussi à l'installeur :
installer: Click droit ---> view---> File system ---> application folder ---> Data et c'est là ou il faut l'ajouter.

Maintenant pour que vous puissiez générer l'installeur il faut aller faire:
 
  lucarne ---> Build , vérifiez que tout est à jour
   ======= Build: 6 succeeded, 0 failed, 0 up-to-date, 0 skipped ===== 
  
  installer--->Build en mode release (il faut faire build pour l'installeur uniquement : 
  click droit sur installer--->Build)

  regarder dans le fichier \Lucarne\Main\src-2015\installer\Release  vous trouverez le fichier .msi et .exe et c'est fini
  
  
