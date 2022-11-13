# MiniProjet

## Le jeu

  Le jeu choisi est Snake.
  L'amélioration est la présence d'ennemis qui veulent du mal au joueur.
  Le joueur pourra se défendre en tirant des lasers.
  Le but du jeu est d'avoir la plus grosse queue possible, pour augmenter la taille de la queue, il faut manger les fruits ( carrés rouges ).
  Des ennemis apparaissent sur les bords de l'écran et le traversent, s'ils touchent la tete de Snake, alors le joueur a perdu.
  Si l'ennemi touche la queue de Snake, alors il la détruit à partir de l'endroit où il l'a touché.
  Snake peut tuer les ennemis, en leur tirant dessus avec son laser. Au bout de 5 ennemis tués, un nouveau fruit apparait ( carré jaune ). 
  Une fois récupéré, ce fruit permet à Snake de tirer plusieurs lasers.
  
 ## Comment compiler ?
 
 gcc -o snake snake.c -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -s -O1 -D_DEFAULT_SOURCE -I. -I/home/bot/Raylib.git/src -I/home/bot/Raylib.git/src/external -I/usr/local/include -L. -L/home/bot/Raylib.git/src -L/home/bot/Raylib.git/src -L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -latomic -DPLATFORM_DESKTOP

 ## Comment exécuter ?  
 
 ./snake
 
 ## Commandes
  
 Pour se déplacer, le joueur utilisera les touches suivantes pour le déplacement correspondant : ARROW_UP / monter; ARROW_DOWN / descendre; ARROW_LEFT / gauche; ARROW_RIGHT / droite.
 Pour utiliser le laser, il suffit d'appuyer sur ESPACE.
 
  ## URL Vidéo
  
  https://www.youtube.com/watch?v=EZ5io_Sqt1w&ab_channel=Co-Meud
