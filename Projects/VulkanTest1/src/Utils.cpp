#include "Utils.h"

bool checkIfGlfwExtensionSupport() {
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> extensions(extensionCount);

	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	uint32_t count = 0;

	for (uint32_t i = 0; i < glfwExtensionCount; ++i) {
		for (const auto& extension : extensions) {

			if (strcmp(glfwExtensions[i], extension.extensionName) == 0) {
				++count;
				break;
			}
		}
	}

	if (count == glfwExtensionCount) {
		return true;
	}

	return false;
}