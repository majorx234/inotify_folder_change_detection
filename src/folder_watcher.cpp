#include <signal.h>
#include <unistd.h>
#include <thread>
#include <memory.h>
#include <iostream>

int do_shutdown = 0;

void sig_int_handler(int sig) {
  do_shutdown = 1;
  std::cout << "Received sig: " << sig
             << " in thread: " << std::this_thread::get_id();
}

int main() {
  struct sigaction action;
  action.sa_handler = sig_int_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  sigaction(SIGINT, &action, NULL);

  while(!do_shutdown) {
    std::cout << "doing work...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  std::cout << "signal received -> finish" << std::endl;
  return 0;

}
