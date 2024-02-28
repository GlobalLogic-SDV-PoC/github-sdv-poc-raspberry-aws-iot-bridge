#include <fstream>

#include "aws_iot/client_iot.hpp"
#include "iotb/app.hpp"
#include "nlohmann/json.hpp"

using namespace std::chrono_literals;

int main()
{
    auto aws_client = std::make_shared<aws_iot::ClientIot>();
    std::ifstream config_file("/var/config/main_config.json");

    iotb::App app(aws_client,
                  nlohmann::json::parse(config_file));
    app.initDefaultLogger("logs/logs.txt", 1'000'000, 5, 5s);
    app.init();
    app.start();
}