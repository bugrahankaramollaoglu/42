<?php

// Get user input
$user_choice = readline("Choose rock, paper, or scissors: ");

// Generate computer choice
$computer_choices = array('rock', 'paper', 'scissors');
$computer_choice = $computer_choices[array_rand($computer_choices)];

// Print choices
echo "You chose $user_choice.\n";
echo "The computer chose $computer_choice.\n";

// Determine winner
if ($user_choice == $computer_choice) {
  echo "It's a tie!\n";
} elseif (($user_choice == 'rock' && $computer_choice == 'scissors') ||
          ($user_choice == 'paper' && $computer_choice == 'rock') ||
          ($user_choice == 'scissors' && $computer_choice == 'paper')) {
  echo "You win!\n";
} else {
  echo "The computer wins!\n";
}


