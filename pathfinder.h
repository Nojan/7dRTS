#ifndef PATHFINDER_H
#define PATHFINDER_H

// include
// std
#include <set>
#include <unordered_map>
#include <unordered_set>

namespace core
{

template <typename Model>
class PathFinder
{
public:
  typedef Model model_t;
  typedef typename model_t::index_t index_t;

  struct Node
  {
    double c, h;
    index_t index;
    Node* parent;

    double score() const
    {
      return c + h;
    }
  };

public:
  std::vector<index_t> find(const model_t& model, const index_t& start, const index_t& objectif);

};


// definition


template <typename M>
inline std::vector<typename M::index_t>
PathFinder<M>::find(const model_t& model, const index_t& start, const index_t& objectif)
{
  /// @todo less by Node->score()
  typedef std::set<Node*> openset_t;
  typedef typename openset_t::const_iterator openset_t_const_iterator;
  openset_t openSet = {new Node{0., model.heuristique(start), start, nullptr}};
  std::unordered_map<index_t, openset_t_const_iterator> openSetByIndex = {{start, openSet.begin()}};
  /// @todo hash by Node->index_t
  std::unordered_set<Node*> closedSet;

  while(!openSet.empty())
  {
    // take best element
    auto bestIt = openSet.begin();
    Node* bestNode = *bestIt;

    if(bestNode->index == objectif)
    {
      ///@todo delete all node in open and closed
      //return reconstruct(*best, closedSet);
    }

    openSetByIndex.erase(bestNode->index);
    openSet.erase(bestIt);
    closedSet.insert(bestNode);
    for(const index_t& neighbor: model.neighbor(bestNode->index))
    {
      Node* candidate = new Node(model.cost(bestNode->index, neighbor),
                                 model.heuristic(neighbor), neighbor, bestNode);
      // if not in closed
      if(closedSet.find(candidate) == std::end(closedSet))
      {
        auto openSetIt = openSetByIndex.find(candidate->index);
        bool neighOk = true;

        if(openSetIt != std::end(openSetByIndex))
        {
          // if candidate is better we delete it in openSet
          if((*openSetIt)->score() > candidate->score())
          {
            openSet.erase(*openSetIt);
            openSetByIndex.erase(openSetIt);
          }
          else
          {
            neighOk = false;
          }
        }

        if(neighOk)
        {
          auto it = openSet.insert(candidate);
          openSetByIndex.insert(candidate->index, it->first);
        }
      }
    }
  }

  /// @todo delete all closed
  return std::vector<index_t>();
}


} // core

#endif // PATHFINDER_H
