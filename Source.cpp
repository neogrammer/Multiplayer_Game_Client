#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <core/Globals.h>
#include <iostream>
#include <core/VideoGame.h>
#include <entities/Player.h>

#include <core/resources/Cfg.h>

//////////////////////////////////
////////////////////////////////
///
/// G U E S T
////////////////////////////

struct MYIP
{
    int num1, num2, num3, num4;
};
MYIP MakeMyIP(std::string ip_);
int main(int argc, char* argv[])
{

    Cfg::Initialize();

    Player host{ "Host",1,100.f,100.f };
    Player guest{ "Guest",2,400.f,100.f };
    bool running = true;
    // as guest you are connecting to the host, no listener on this one
    std::string ip;
    std::cout << "Type in the ip address of the host: " << std::endl;
    std::cin >> ip;
   // std::cout << "\nAnd the port it is listening on: " << std::endl;    
    //int port = 53000;
    //std::cin >> port;

   MYIP ipaddress = MakeMyIP(ip);
  
    sf::TcpSocket::Status status{};

    sf::TcpSocket      socket;
    status = socket.connect(sf::IpAddress((uint8_t)ipaddress.num1, (uint8_t)ipaddress.num2, (uint8_t)ipaddress.num3, (uint8_t)ipaddress.num4), 53000);
    //status = socket.connect({(uint8_t)ipaddress.num1, (uint8_t)ipaddress.num2, (uint8_t)ipaddress.num3, (uint8_t)ipaddress.num4 }, port);   
    if (status != sf::TcpSocket::Status::Done)
    {
        std::cout << "Error" << std::endl;
        running = false;
    }
    // this will connect

    //std::cout << "\n" << (uint8_t)ipaddress.num1 << " : " << (uint8_t)ipaddress.num2 << " : " << (uint8_t)ipaddress.num3 << " : " << (uint8_t)ipaddress.num4 << std::endl;

    CidWindow window;
    window.create((int)glb::WINW, (int)glb::WINH, "SFML3 Game", sf::State::Windowed);
    window.setPosition({ 100, 300 });

    bool soWhat = ImGui::SFML::Init(window, false);
    soWhat = false;

    auto& IO = ImGui::GetIO();
    IO.Fonts->Clear(); // clear fonts if you loaded some before (even if only default one was loaded)
    // IO.Fonts->AddFontDefault(); // this will load default font as well
    IO.Fonts->AddFontFromFileTTF("Assets\\Fonts\\Crusty.ttf", 18.f);



    // change the position of the window (relatively to the desktop)
    //window.setPosition({ 400, 200 });

    // change the title of the window
    window.setTitle("SFML window");


    VideoGame game{&host, &guest, &window };


    // run the program as long as the window is open
    sf::Clock deltaClock;


    while (running && window.isOpen())
    {
        // you are guest, send first, they are waiting to receive
        std::string nameP2 = "Guest";
        uint32_t idP2 = 2;
        float xPosP2 = guest.xpos;
        float yPosP2 = guest.ypos;
        sf::Packet packet;
        packet << nameP2 << idP2 << xPosP2 << yPosP2;

        status = socket.send(packet); // blocking, maybe turn off blocking and use a selector?


        if (status != sf::TcpSocket::Status::Done)
        {
            std::cout << "Error" << std::endl;
            running = false;
        }




        // now just sent so its time to wait for a reply
        std::string nameP1;
        uint32_t idP1;
        float xPosP1;
        float yPosP1;
        {
            sf::Packet packet;
            status = socket.receive(packet); // blocking    
            if (status != sf::TcpSocket::Status::Done)
            {
                std::cout << "Error" << std::endl;
                running = false;
            }
            bool error = true;
            if (packet >> nameP1) {
                if (packet >> idP1) {
                    if (packet >> xPosP1) {
                        if (packet >> yPosP1)
                        {
                            // only got here if all variables are now filled correctly
                            error = false;
                            host.name = nameP1;
                            host.id = idP1;
                            host.xpos = xPosP1;
                            host.ypos = yPosP1;
                        }
                    }
                }
            }
            if (error)
            {
                std::cout << "Error reading in the data" << std::endl;
                //throw an error
            }
        }
        // now that both are sent to each other and updated , run a game frame and then start back over reading and writing every frame.
        std::cout << host.name << host.id << host.xpos << host.ypos << std::endl;

        game.input();
        if (running)
        {

            // check all the window's events that were triggered since the last iteration of the loop
            while (const std::optional event = window.pollEvent())
            {
                ImGui::SFML::ProcessEvent(window, *event);
                // "close requested" event: we close the window
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                    break;
                }
                else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                {
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    {
                        window.close();
                        break;
                    }
                }
            }
            sf::Time dt = deltaClock.restart();
            
            
         
            game.update(dt);

            soWhat = ImGui::SFML::UpdateFontTexture(); // important call: updates font texture
            ImGui::SFML::Update(window, deltaClock.restart());

            ImGui::Begin("Hello, world!");
            ImGui::Button("Look at this pretty button");
            ImGui::End();

            window.clear(sf::Color(47, 147, 247, 255));

            game.render();

            ImGui::SFML::Render(window);
            window.display();
        }
    }
    if (window.isOpen())
    {
        window.close();
    }
   ImGui::SFML::Shutdown();
	    
   return 69;
}

MYIP MakeMyIP(std::string ip_)
{
    std::string one, two, three, four;
    size_t dot1 = ip_.find_first_of('.');
    one = ip_.substr(0, dot1);
    size_t dot2 = ip_.substr(dot1+1, ip_.length() - dot1 - 1).find_first_of('.');

    two = ip_.substr(dot1+1, dot2);
    size_t dot3 = ip_.substr(dot1 + dot2 + 2, ip_.length() - dot1 - dot2 - 2).find_first_of('.');

    three = ip_.substr(dot1 + dot2 + 2, dot3);
   // int dot4 = ip_.substr(dot1 + dot2 + dot3 + 3, ip_.length() - dot1 - dot2 - dot3 - 3).find_first_of('.');

    four = ip_.substr(dot1 + dot2 + dot3 + 3, ip_.length() - dot1 - dot2 - dot3 - 3);
    MYIP ip{ atoi(one.c_str()),atoi(two.c_str()),atoi(three.c_str()),atoi(four.c_str()) };
    return ip;
}
