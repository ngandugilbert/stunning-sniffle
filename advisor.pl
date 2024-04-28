% Some facts
investment(savings) :- savings_account(inadequate).
investment(stocks) :- savings_account(adequate), income(adequate).
investment(combination) :- savings_account(adequate), income(inadequate).

%rules
min_savings(Dependents, Amount) :- Amount is 5000 * Dependents. % Have a minimum of 5000 for each dependent
min_income(Dependents, Amount) :- Amount is 15000 + (4000 * Dependents). % Adequate income per year is at least 15000 plus 4000 for each dependent

savings_account(adequate) :- amount_saved(Amount),numDependents(Dependents),min_savings(Dependents,SavingsMin),Amount > SavingsMin.
savings_account(inadequate) :- amount_saved(Amount),numDependents(Dependents),min_savings(Dependents, SavingsMin), Amount =< SavingsMin.

income(adequate) :- earnings(AmountEarned, steady), numDependents(Dependents),min_income(Dependents, IncomeMin), AmountEarned > IncomeMin.
income(inadequate) :- earnings(AmountEarned, steady),numDependents(Dependents),min_income(Dependents, IncomeMin), AmountEarned =< IncomeMin.

income(inadequate) :- earnings(AmountEarned, unsteady).
income(inadequate) :- earnings(AmountEarned, unsteady).

% assertions
amount_saved(22000).
numDependents(3).
earnings(28000,steady).