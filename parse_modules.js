const fs = require('fs');
const path = require('path');

function processDirectory(dirPath) {
    const result = {
        name: path.basename(dirPath),
        type: 'directory',
        children: []
    };

    const items = fs.readdirSync(dirPath);

    for (const item of items) {
        const fullPath = path.join(dirPath, item);
        const stats = fs.statSync(fullPath);

        if (stats.isDirectory()) {
            const subdirResult = processDirectory(fullPath);
            if (subdirResult.children.length > 0) { // Only include directories with relevant files
                result.children.push(subdirResult);
            }
        } else {
            const ext = path.extname(item).toLowerCase();
            if (['.cpp', '.hpp'].includes(ext)) {
                const content = fs.readFileSync(fullPath, 'utf8');
                result.children.push({
                    name: item,
                    type: 'file',
                    extension: ext,
                    content: content
                });
            }
        }
    }

    // Sort children: directories first, then files
    result.children.sort((a, b) => {
        if (a.type === b.type) {
            return a.name.localeCompare(b.name);
        }
        return a.type === 'directory' ? -1 : 1;
    });

    return result;
}

// Starting point
const rootDir = '.'; // Adjust this path as needed
const output = processDirectory(rootDir);

// Write to file
fs.writeFileSync(
    'cpp_modules_structure.json',
    JSON.stringify(output, null, 2),
    'utf8'
);

console.log('Processing complete! Check cpp_modules_structure.json for the result.');