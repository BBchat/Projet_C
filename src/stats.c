#include <stdio.h>
#include <stdlib.h>
#include "../include/stats.h"
#include "../include/transaction.h"
#include "../include/loaded_transactions.h"


//renvoi où on en est actuellement de ce type de transaction (positif ou négatif de combien)
double get_total_type_i(int i) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL) {
    if (current_trs->type == i) {
      result = result + (current_trs->amount);
    }
    current_trs = (*current_trs).next;
  };
  return result;
}

//retourne toutes les entrées d'argent du type i (sur le csv entier)
double get_in_type_i(int i) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL) {
    if (current_trs->type == i) {
      if (current_trs->amount > 0) {
        result += (current_trs->amount);
      }
    }
  current_trs = (*current_trs).next;
  };
  return result;
}

//retourne toutes les dépenses du type i (sur le csv entier)
double get_out_type_i(int i) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL) {
    if (current_trs->type == i) {
      if (current_trs->amount < 0) {
        result += (current_trs->amount);
      }
    }
  current_trs = (*current_trs).next;
  };
  return result;
}

//total des dépenses (sur le csv entier)
double total_out() {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL) {
    if (current_trs->amount < 0) {
      result += current_trs->amount;
    }
    current_trs = (*current_trs).next;
  };
  return result;
}

//total des rentrées d'argent (sur le csv entier)
double total_in() {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL) {
    if (current_trs->amount > 0) {
      result += current_trs->amount;
    }
    current_trs = (*current_trs).next;
  };
  return result;
}

//pourcentage de dépense d'un type i par rapport à total_out (sur le csv entier donc)
double i_comparedTo_total(int i) {
  double total_i = get_out_type_i(i);
  double total = total_out();
  double result = 0;

  if (total != 0) {
    result = (total_i/total)*100;
  }
  else {
    printf("%s\n", "Vous n'avez jamais rien depense ! Bravo !");
  }
  return result;
}

//total des dépenses sur un mois donné d'une année donnée
double total_out_month(int m, int y) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL && (current_trs->date)->year != y && (current_trs->date)->month != m) {
    current_trs = (*current_trs).next;
  };

  while (current_trs != NULL && (current_trs->date)->year == y && (current_trs->date)->month == m) {
    if(current_trs->amount<0) {
      result += current_trs->amount;
    }
    current_trs = (*current_trs).next;
  };

  return result;
}

//total des entrées d'argent sur un mois donné d'une année donnée
double total_in_month(int m, int y) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL && (current_trs->date)->year != y && (current_trs->date)->month != m) {
    current_trs = (*current_trs).next;
  };

  while (current_trs != NULL && (current_trs->date)->year == y && (current_trs->date)->month == m) {
    if(current_trs->amount > 0) {
      result += current_trs->amount;
    }
    current_trs = (*current_trs).next;
  };

  return result;
}

//total des dépenses de type i sur un mois donné d'une année donnée
double total_out_i_month(int m, int y, int i) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL && (current_trs->date)->year != y && (current_trs->date)->month != m) {
    current_trs = (*current_trs).next;
  };

  while (current_trs != NULL && (current_trs->date)->year == y && (current_trs->date)->month == m) {
    if (current_trs->type == i) {
      if(current_trs->amount < 0) {
        result += current_trs->amount;
      }
    }
    current_trs = (*current_trs).next;
  };

  return result;
}

//total des entrées d'argent de type i sur un mois donné d'une année donnée
double total_in_i_month(int m, int y, int i) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL && (current_trs->date)->year != y && (current_trs->date)->month != m) {
    current_trs = (*current_trs).next;
  };

  while (current_trs != NULL && (current_trs->date)->year == y && (current_trs->date)->month == m) {
    if (current_trs->type == i) {
      if(current_trs->amount > 0) {
        result += current_trs->amount;
      }
    }
    current_trs = (*current_trs).next;
  };

  return result;
}

//pourcentage de dépense d'un type i sur un mois donné d'une année donnée
double i_comparedTo_month(int m, int y, int i) {
  double total_i = total_out_i_month(m, y, i);
  double total =  total_out_month(m, y);
  double result = 0;

  if (total != 0) {
    result = (total_i/total)*100;
  }
  else {
    printf("%s%d%s%d\n", "Vous n'avez rien depense le mois ", m, " de l'annee ", y);
  }
  return result;
}

//toutes les dépenses sur une année données
double total_out_year(int y) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL && (current_trs->date)->year != y) {
    current_trs = (*current_trs).next;
  };

  while (current_trs != NULL && (current_trs->date)->year == y) {
    if(current_trs->amount<0) {
      result += current_trs->amount;
    }
    current_trs = (*current_trs).next;
  };

  return result;
}

//toutes les rentrées d'argent sur une année donnée
double total_in_year(int y) {
  double result = 0;
  Transaction* current_trs = get_first_transaction();

  while (current_trs != NULL && (current_trs->date)->year != y) {
    current_trs = (*current_trs).next;
  };

  while (current_trs != NULL && (current_trs->date)->year == y) {
    if(current_trs->amount>0) {
      result += current_trs->amount;
    }
    current_trs = (*current_trs).next;
  };

  return result;
}

//pourcentage de dépenses d'un mois donné d'une année, par rapport aux dépenses de l'année
double month_comparedTo_year(int m, int y) {
  double total_i = total_out_month(m, y);
  double total =  total_out_year(y);
  double result = 0;

  if (total != 0) {
    result = (total_i/total)*100;
  }
  else {
    printf("%s%d%s\n", "Vous n'avez rien depense l'annee ", y, " ! Waouh !");
  }
  return result;
}
