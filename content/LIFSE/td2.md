# exercice 1

## 1ere question

### 1ere maniere

```cpp
int main(){
  int ret1;
  ret1 = fork();
  if (fork() == 0){// on est donc dans le fils 1
    if (fork() == 0){//on est dans le fils 2
      return 0;
    }
    wait(NULL);
    return 0;
  }
  wait(NULL);
  return 0;
}
```

### 2eme maniere

deux types de notation: == 0 ou > 0`

```cpp
int main(){
  int ret1;
  ret1 = fork();
  if (fork() > 0){
  // pere: car fork renvoie 
    wait(NULL);
    return 0;
  } else { // processus fils 1
    if (fork() > 0){
      wait(NULL);
      return 0;
    } else{
      wait(NULL);
      return 0;
    }
  }
}
```

quand processus fils se termine il passe a letat de zombie
=> ses ressources ne sont pas libres
=> wait() permets de faire disparaitre le fils

## 2eme question

#### 3)

```cpp
int main(){
  for (int i=0;i<3;i++){
    if (fork() > 0){
      wait(NULL);
      break;
    }
  }
  return 0;
}
```

# exercice 2

```cpp
int pid1 = fork();
if(pid1 == 0) { // code exécuté par le fils
  return 0;
}
int pid2 = fork();
if(pid2 == 0) { // code exécuté par le fils
  return 0;
waitpid(pid1,NULL,0); //attente fils1
waitpid(pid2,NULL,0); //attente fils2
}
// code exécuté par le père
```

```cpp
int main(){
  int pid1 = fork();
  if (pid1 == 0)
    return 0;
  int pid2 = fork();
  if (pid2 == 0){
    int pid3 = fork();
    if (pid3 == 0)
      return 0;
    int pid4 = fork();
    waitpid(pid3,NULL,0);
    waitpid(pid4,NULL,0);
    return 0;
  }
  waitpid(pid1,NULL,0);
  waitpid(pid2,NULL,0);
  
}
```

## partie 2

### a)

```cpp
int pid[4];
for (int i = 0 ; i < 4 ; i++){
  pid[i] = fork();
  if (pid[0] == 0)
    return 0;
}
```

# exercice 3

```cpp
int main(void) {
  if( fork() > 0 ) {
      wait(NULL);
    }
    else {
      sleep(5);
  }
return 0;
}
```

## 1er programme

le fils dors 5secondes

## 2eme programme

le pere et le fils dorment 5 secondes (en meme temps)

## 3eme programme

le pere attends que le fils ait finis de dormir (avant de dormir lui aussi)=>donc tout le monde dors

## 4eme programme

on fait sleep(5) sans faire de verification si pere ou fils:
