//
// Created by Daniel HADLEY on 2019-04-06.
//

#ifndef WORKINGVERSION_GRAPHICALVIEW_HPP
#define WORKINGVERSION_GRAPHICALVIEW_HPP

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
# include "IMonitorDisplay.hpp"

class GraphicalView : public IMonitorDisplay {
 public:
  GraphicalView();

  virtual ~GraphicalView();

  virtual void updateModule();

  virtual void render();

  virtual void addModule(IMonitorModule *toAdd);

  virtual void removeModule(IMonitorModule const *target);

  sf::RenderWindow *_window;

 private:
  GraphicalView(GraphicalView const &copy);

  GraphicalView &operator=(GraphicalView const &copy);

  std::vector<IMonitorModule *> _module;

  std::vector<sf::RectangleShape*> _moduleShapes;


};


#endif //WORKINGVERSION_GRAPHICALVIEW_HPP
