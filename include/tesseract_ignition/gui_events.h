/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef TESSERACT_IGNITION_GUI_EVENTS_H
#define TESSERACT_IGNITION_GUI_EVENTS_H
#include <QEvent>
#include <utility>
#include <vector>
#include <ignition/math/Vector3.hh>
//#include "ignition/gazebo/Entity.hh"

namespace tesseract_ignition
{
namespace gui
{

/// \brief Namespace for all events. Refer to the EventManager class for
/// more information about events.
namespace events
{
  /// \brief The class for sending and receiving custom snap value events.
  class SnapIntervals : public QEvent
  {
    /// \brief Constructor
    /// \param[in] _xyz XYZ snapping values.
    /// \param[in] _rpy RPY snapping values.
    /// \param[in] _scale Scale snapping values.
    public: SnapIntervals(
                const ignition::math::Vector3d &_xyz,
                const ignition::math::Vector3d &_rpy,
                const ignition::math::Vector3d &_scale)
    : QEvent(kType), xyz(_xyz), rpy(_rpy), scale(_scale)
    {
    }

    /// \brief Get the XYZ snapping values.
    /// \return The XYZ snapping values.
    public: ignition::math::Vector3d XYZ() const
    {
      return this->xyz;
    }

    /// \brief Get the RPY snapping values.
    /// \return The RPY snapping values.
    public: ignition::math::Vector3d RPY() const
    {
      return this->rpy;
    }

    /// \brief Get the scale snapping values.
    /// \return The scale snapping values.
    public: ignition::math::Vector3d Scale() const
    {
      return this->scale;
    }

    /// \brief The QEvent representing a snap event occurrence.
    static const QEvent::Type kType = QEvent::Type(QEvent::User);

    /// \brief XYZ snapping values in meters, these values must be positive.
    private: ignition::math::Vector3d xyz;

    /// \brief RPY snapping values in degrees, these values must be positive.
    private: ignition::math::Vector3d rpy;

    /// \brief Scale snapping values - a multiplier of the current size,
    /// these values must be positive.
    private: ignition::math::Vector3d scale;
  };

  /// \brief Event that notifies when new entities have been selected.
//  class EntitiesSelected : public QEvent
//  {
//    /// \brief Constructor
//    /// \param[in] _entities All the selected entities
//    /// \param[in] _fromUser True if the event was directly generated by the
//    /// user, false in case it's been propagated through a different mechanism.
//    public: explicit EntitiesSelected(
//        const std::vector<Entity> &_entities,  // NOLINT
//        bool _fromUser = false)
//        : QEvent(kType), entities(_entities), fromUser(_fromUser)
//    {
//    }

//    /// \brief Get the data sent with the event.
//    /// \return The entities being selected.
//    public: std::vector<Entity> Data() const
//    {
//      return this->entities;
//    }

//    /// \brief Get whether the event was generated by the user.
//    /// \return True for the user.
//    public: bool FromUser() const
//    {
//      return this->fromUser;
//    }

//    /// \brief Unique type for this event.
//    static const QEvent::Type kType = QEvent::Type(QEvent::User + 1);

//    /// \brief The selected entities.
//    private: std::vector<Entity> entities;

//    /// \brief Whether the event was generated by the user,
//    private: bool fromUser{false};
//  };

  /// \brief Event that notifies when all entities have been deselected.
  class DeselectAllEntities : public QEvent
  {
    /// \brief Constructor
    /// \param[in] _fromUser True if the event was directly generated by the
    /// user, false in case it's been propagated through a different mechanism.
    public: explicit DeselectAllEntities(bool _fromUser = false)
        : QEvent(kType), fromUser(_fromUser)
    {
    }

    /// \brief Get whether the event was generated by the user.
    /// \return True for the user.
    public: bool FromUser() const
    {
      return this->fromUser;
    }

    /// \brief Unique type for this event.
    static const QEvent::Type kType = QEvent::Type(QEvent::User + 2);

    /// \brief Whether the event was generated by the user,
    private: bool fromUser{false};
  };

  /// \brief Event called in the render thread of a 3D scene.
  /// It's safe to make rendering calls in this event's callback.
  class Render : public QEvent
  {
    public: Render()
        : QEvent(Type)
    {
    }
    /// \brief Unique type for this event.
    static const QEvent::Type Type = QEvent::Type(QEvent::User + 3);
  };
}
}  // namespace gui
}  // namespace tesseract_ignition
#endif // TESSERACT_IGNITION_GUI_EVENTS_H
