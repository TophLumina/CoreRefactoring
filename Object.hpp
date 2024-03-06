#pragma once

/**
 * @brief The Object class represents a base class for all objects in the system.
 */
class Object
{
public:
    int instance_id;

    /**
     * @brief Constructs an Object with the specified instance ID.
     * @param _instance_id The instance ID of the Object.
     */
    Object(unsigned int _instance_id = 0) : instance_id(_instance_id) {};

    Object(const Object &other) = delete;
    Object &operator=(const Object &other) = delete;

    Object(Object &&other) = delete;
    Object &operator=(Object &&other) = delete;

    /**
     * @brief Destroys the Object.
     */
    virtual ~Object() {}

    /**
     * @brief Destroys the Object and releases any resources associated with it.
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void Destroy() = 0;
};

/**
 * @brief Interface for objects that can be awakened with arguments.
 * 
 * This interface defines a method for awakening an object with a variable number of arguments.
 * The Awake method must be implemented by any class that inherits from this interface.
 * 
 * @tparam Args The types of the arguments that can be passed to the Awake method.
 */
template<typename ... Args>
class Awakeable
{
public:
    /**
     * @brief Awakens the object with the specified arguments.
     * 
     * Thi * 
 * This class defines an interface for objects that can be started.
 * The Start method must be implemented by derived classes.
 * 
s method is called to awaken the object with the specified arguments.
     * The implementation of this method should handle the awakening logic.
     * 
     * @param args The arguments to be passed to the Awake method.
     */
    virtual void Awake(Args... args) = 0;
};

/**
 * @brief Template specialization for Awakeable class.
 * 
 * This class provides an interface for objects that can be awakened.
 * Subclasses must implement the Awake() method.
 */
template<>
class Awakeable<>
{
public:
    /**
     * @brief Awake the object.
     * 
     * This method is called to awaken the object.
     * Subclasses must implement this method.
     */
    virtual void Awake() = 0;
};

/**
 * @brief A template class representing a startable object.
late specialization for the Updateable class.
 * 
 * This class provides an interface for objects that can be updated.
 * Derived classes must implement the Update() function.
 */
template<>
class Updateable<>
{
public:
    /**
     * @brief Update the object.
     * 
     * This function must be implemented by derived classes.
     */
    virtual void Update() = 0;
};

/**
 class defines an interface for objects that can be started.
 * The Star * 
 * This interface defines a method for performing late update operations on objects.
 * The LateUpdate method should be implemented by derived classes to define the specific
 * late update behavior.
 * 
t method must be implemented by derived classes.
 * 
 * @tparam Args The types of arguments that can be passed to the Start method.
 */
template<typename ... Args>
class Startable
{
public:
    /**
     * @brief Starts the object.
     * 
     * This method starts the object with the specified arguments.
     * Derived classes must implement this method.
     * 
     * @param args The arguments to be passed to the Start method.
     */
    virtual void Start(Args... args) = 0;
};

/**
 * @brief Template specialization for the Startable class.
 * 
 * This class represents a startable object, which can be started by calling the Start() method.
 * It is an abstract class with a pure virtual Start() method.
 * 
 * @tparam T The type of the object.
 */
template<>
class Startable<>
{
public:
    /**
     * @brief Starts the object.
     * 
     * This method must be implemented by derived classes to define the start behavior of the object.
     */
    virtual void Start() = 0;
};

/**
 * @brief An interface for objects that can be updated with arguments.
 * 
 * This class defines an interface for objects that can be updated with a variable number of arguments.
 * The Update method must be implemented by derived classes to perform the update operation.
 * 
 * @tparam Args The types of the arguments that can be passed to the Update method.
 */
template<typename ... Args>
class Updateable
{
public:
    /**
     * @brief Updates the object with the specified arguments.
     * 
     * This method must be implemented by derived classes to perform the update operation.
     * The number and types of the arguments can vary depending on the implementation.
     * 
     * @param args The arguments to be passed to the update operation.
     */
    virtual void Update(Args... args) = 0;
};

/**
 * @brief Template specialization for the Updateable class.
 * 
 * This class provides an interface for objects that can be updated.
 * Derived classes must implement the Update() function.
 */
template<>
class Updateable<>
{
public:
    /**
     * @brief Update the object.
     * 
     * This function must be implemented by derived classes.
     */
    virtual void Update() = 0;
};

/**
 * @brief Interface for objects that require late update functionality.
 * 
 * This interface defines a method for performing late update operations on objects.
 * The LateUpdate method should be implemented by derived classes to define the specific
 * late update behavior.
 * 
 * @tparam Args The types of the arguments that can be passed to the LateUpdate method.
 */
template<typename ... Args>
class LateUpdateable
{
public:
    /**
     * @brief Perform a late update operation.
     * 
     * This method should be implemented by derived classes to define the specific
     * late update behavior.
     * 
     * @param args The arguments to be passed to the LateUpdate method.
     */
    virtual void LateUpdate(Args... args) = 0;
};

/**
 * @brief A template class for objects that can be updated late in the frame.
 * 
 * This class provides an interface for objects that need to perform late updates
 * in the game loop. Any class that inherits from this template must implement
 * the LateUpdate() function.
 */
template<>
class LateUpdateable<>
{
public:
    /**
     * @brief Perform a late update.
     * 
     * This function is called during the late update phase of the game loop.
     * Subclasses must implement this function to define their specific late
     * update behavior.
     */
    virtual void LateUpdate() = 0;
};

enum class RenderLayer : unsigned int
{
    Background = 0,
    Default    = 500,
    Foreground = 1000
};

/**
 * @brief A template class representing a renderable object.
 * 
 * This class provides a common interface for objects that can be rendered.
 * It defines a pure virtual function Render() that must be implemented by derived classes.
 * The Render() function takes a variable number of arguments of type Args.
 * 
 * @tparam Args The types of the arguments that can be passed to the Render() function.
 */
template <typename... Args>
class Renderable
{
public:
    RenderLayer layer;
    /**
     * @brief Renders the object.
     * 
     * This function must be implemented by derived classes.
     * It takes a variable number of arguments of type Args.
     * 
     * @param args The arguments to be passed to the Render() function.
     */
    virtual void Render(Args... args) = 0;
};