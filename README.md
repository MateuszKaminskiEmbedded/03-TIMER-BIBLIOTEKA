# TIMER-BIBLIOTEKA

Biblioteka posiada dwie funkcje, pierwsza z nich łączy timer drugi z trzecim tworząc 32-bitowy timer, który pracuje w trybie bramkowym. Druga funkcja konfiguruje
timer 2 do pracy w trybie 16-bitowego licznika synchronicznego.

Plik timer.h
W pliku tym znajdują się deklaracje funkcji oraz tworzona jest stała przechowująca częstotliwość pracy mikrokontrolera.

Plik timer.c
W definicji funkcji Timer23Gated_Init() skonfigurowano timer 2 w taki sposób, żeby razem z timerem trzecim, tworzył jeden timer 32-bitowy. Posiada priorytet o 
indeksie 3 i subpriorytet o indeksie 1. Timer ma skonfigurowany preskaler na wartość 256. Stan wysoki na wybranym pinie powoduje rozpoczęcie liczenia, a stan niski jego koniec. W celu dobrania preskalera do mierzenia oczekiwanej częstotliwości lub impulsów, można posłóżyć się poniższą tebelą częstotliwości:

![image](https://user-images.githubusercontent.com/104322532/198850644-a48ce941-90bb-4c28-aa3f-310947633723.png)

W definicji funkcji Timer2_Init(frequency) ustawiono priorytety w taki sam sposób jak w poprzedniej funkcji, a preskaler ustawiono na wartość 8.

plik main.c
W tym pliku umieszczono funkcję obsługo przerwania dla obu funkcji biblioteki. Umieszczono także konfigurację używanych pinów.

W celu użycia biblioteki należy:
1) Dodać pliki do projektu
2) Zdefiniować lub zaktualizować (plik timer.h) stałą SYS_FREQ wartością częsotliwości pracy mikrokontrolera
3) Ustawić wartości preskalerów i priorytetów w pliku timer.c do własnych potrzeb
4) W pliku głównym programu wywołać funkcję timera, zdefiniować piny, których używa timer oraz uzupełnić funkcję obsługi przerwania o własny kod wykonywany
w przerwaniu
5) Timer jest gotowy do działania
