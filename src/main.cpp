#include <dpp/dpp.h>
#include "token.h"
#include "config.h"


int main() {
    dpp::cluster bot(BOT_TOKEN);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "ping") {
            event.reply("Xi Jin PingPingYee");
        }
		if (event.command.get_command_name() == "bruh") {
			std::string animal = std::get<std::string>(event.get_parameter("animal"));
			event.reply(std::string("Bruh! You chose") + animal);
		}
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
	    if (dpp::run_once<struct register_bot_commands>()) {
	        bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));

			dpp::slashcommand bruhcommand("bruh", "Send a random adorable animal photo", bot.me.id);
			bruhcommand.add_option(
				dpp::command_option(dpp::co_string, "animal", "Animal Type", true)
					.add_choice(dpp::command_option_choice("Dog", std::string("animal_dog")))
					.add_choice(dpp::command_option_choice("Cat", std::string("animal_cat")))
					.add_choice(dpp::command_option_choice("Penguin", std::string("animal_penguin"))
				)
			);

			bot.global_command_create(bruhcommand);

	    }
	});


    bot.start(dpp::st_wait);

	return 0;
}
