#ifndef PATHFINDER_H
#define PATHFINDER_H

// include
// std
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>


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

    struct hash
    {
      std::size_t operator()(const Node* node) const
      {
        return std::hash<index_t>()(node->index);
      }
    };

    struct equal
    {
      bool operator()(const Node* n1, const Node* n2) const
      {
        return n1->index == n2->index;
      }
    };

    struct less
    {
      bool operator()(const Node* n1, const Node* n2) const
      {
        return n1->score() < n2->score();
      }
    };
  };

public:
  std::vector<index_t> find(const model_t& model, const index_t& start, const index_t& objectif);

};


// definition



template <typename M>
inline std::vector<typename M::index_t>
PathFinder<M>::find(const model_t& model, const index_t& start, const index_t& objectif)
{
  typedef std::multiset<Node*, typename Node::less> openset_t;
  typedef typename openset_t::const_iterator openset_t_const_iterator;

  openset_t openSet = {new Node{0., model.heuristic(start, objectif), start, nullptr}};
  std::unordered_map<index_t, openset_t_const_iterator> openSetByIndex = {{start, openSet.begin()}};
  std::unordered_set<Node*, typename Node::hash, typename Node::equal> closedSet;

  while(!openSet.empty())
  {
    // take best element
    auto bestIt = openSet.begin();
    Node* bestNode = *bestIt;

    if(bestNode->index == objectif)
    {
      ///@todo delete all node in open and closed
      std::size_t nrNode = 0;
      Node* curNode = bestNode;
      while(curNode)
      {
        ++nrNode;
        curNode = curNode->parent;
      }

      std::vector<index_t> result(nrNode);
      curNode = bestNode;
      for(std::size_t i = 0; i < nrNode; ++i)
      {
        result[nrNode - i - 1] = curNode->index;
        curNode = curNode->parent;
      }

      return result;
    }

    openSetByIndex.erase(bestNode->index);
    openSet.erase(bestIt);
    closedSet.insert(bestNode);
    for(const index_t& neighbor: model.neighbor(bestNode->index))
    {
      Node* candidate = new Node{bestNode->c + model.cost(bestNode->index, neighbor),
                                 model.heuristic(neighbor, objectif), neighbor, bestNode};
      // if not in closed
      if(closedSet.find(candidate) == std::end(closedSet))
      {
        auto openSetIt = openSetByIndex.find(candidate->index);
        bool neighOk = true;

        if(openSetIt != std::end(openSetByIndex))
        {
          // if candidate is better we delete it in openSet
          if((*openSetIt->second)->c > candidate->c)
          {
            openSet.erase(openSetIt->second);
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
          openSetByIndex.insert({candidate->index, it});
        }
      }
    }
  }

  /// @todo delete all closed
  return std::vector<index_t>();
}


} // core

#endif // PATHFINDER_H
