// #include <stdio.h>
// #include <string.h>

// int main() {
//   char Q[] = {'A', 'B', 'C', 'D', 'E'};
//   int q = 5;

//   char S[] = {'0', '1'};
//   int s = 2;

//   char init = 'A';
//   char final[] = {'B', 'D'};

//   char table[5][2] = {
//       {'E', 'B'}, {'B', 'C'}, {'D', 'C'}, {'E', 'E'}, {'E', 'E'}};

//   char input[100];

//   int flag = 1;

//   while (1) {
//     printf("Enter input String:\n");
//     scanf("%s", input);

//     for (int i = 0; i < strlen(input); i++) {
//       if (input[i] != '0' && input[i] != '1') {
//         flag = 0;
//         break;
//       }
//     }

//     if (flag) {
//       break;
//     }
//     printf("Invalid String. Try again.\n");
//   }

//   char cur = 'A';
//   for (int i = 0; i < strlen(input); i++) {
//     char a = input[i];

//     int j = 0;
//     while (j < q) {
//       if (Q[j] == cur) {
//         break;
//       }
//       j++;
//     }

//     int k = a == '0' ? 0 : 1;

//     cur = table[j][k];
//   }

//   if (cur == final[0] || cur == final[1]) {
//     printf("ACCEPTED");
//   } else {
//     printf("REJECTED");
//   }
// }

#include <stdio.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 10

int main() {
  int numStates;
  char states[MAX_STATES];
  int numSymbols;
  char symbols[MAX_SYMBOLS];
  char initialState;
  int numFinalStates;
  char finalStates[MAX_STATES];
  char transitions[MAX_STATES][MAX_SYMBOLS];

  char input[100];

  printf("Enter the number of states: ");
  scanf("%d", &numStates);

  printf("Enter the states: ");
  for (int i = 0; i < numStates; i++) {
    scanf(" %c", &states[i]);
  }

  printf("Enter the number of symbols: ");
  scanf("%d", &numSymbols);

  printf("Enter the states: ");
  for (int i = 0; i < numSymbols; i++) {
    scanf(" %c", &symbols[i]);
  }

  printf("Enter the initial state: ");
  scanf(" %c", &initialState);

  printf("Enter the number of final states: ");
  scanf("%d", &numFinalStates);

  printf("Enter the final states: ");
  for (int i = 0; i < numFinalStates; i++) {
    scanf(" %c", &finalStates[i]);
  }

  printf("Enter the transition table:\n");

  for (int i = 0; i < numStates; i++) {
    for (int j = 0; j < numSymbols; j++) {
      printf("Transition for state %c and symbol %c: ", states[i], symbols[j]);
      scanf(" %c", &transitions[i][j]);
    }
  }

  printf("States:\n");
  for (int i = 0; i < numStates; i++) {
    printf("%c ", states[i]);
  }

  printf("\nSymbold:\n");
  for (int i = 0; i < numSymbols; i++) {
    printf("%c ", symbols[i]);
  }

  printf("\ninit satet:\n");
  // for (int i = 0; i < numStates; i++) {
  printf("%c", initialState);

  printf("\nfinals States:\n");
  for (int i = 0; i < numFinalStates; i++) {
    printf("%c ", finalStates[i]);
  }

  printf("\nTT:\n");
  for (int i = 0; i < numStates; i++) {
    for (int j = 0; j < numSymbols; j++) {
      printf("%c ", transitions[i][j]);
    }
    printf("\n");
  }

  printf("Enter the input string: ");
  scanf("%s", input);

  char currentState = initialState;

  for (int i = 0; i < strlen(input); i++) {
    char symbol = input[i];

    int j = 0;
    while (j < numStates) {
      if (currentState == states[j]) {
        break;
      }
      j++;
    }

    int k = 0;
    while (k < numSymbols) {
      if (symbol == symbols[k]) {
        break;
      }
      k++;
    }

    char currentState = transitions[j][k];
  }

  for (int i = 0; i < numFinalStates; i++) {
    if (currentState == finalStates[i]) {
      printf("ACCEPTED");
      return 1;
    }
  }

  printf("REJECTED");
}